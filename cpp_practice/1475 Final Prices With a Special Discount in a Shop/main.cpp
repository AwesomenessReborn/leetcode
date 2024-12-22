// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=problem-list-v2&envId=monotonic-stack

#include <stack> 
#include <bitset>
#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <iterator> 
#include <vector>
#include <ios>
#include <limits>
#include <sstream> 
#include <string> 

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

template <typename T>
void printArray(std::vector<T> values) {
    std::cout << "["; 
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i]; 
        if (values.size() - 1 > i) {
            std::cout << ", "; 
        }
    }
    std::cout << "]" << std::endl; 
}


struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

// return index of target: 
int binSearch(vector<int> arr, int x) {

    int left = 0, right = arr.size()-1; 
    int mid; 

    while (left <= right) {
        mid = left + (right - left) / 2; 

        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] > x) {
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    if (right < 0) return 0; 
    if (left >= arr.size()) return arr.size() - 1; 

    if (abs(arr[left]-x) < abs(arr[right] - x)) {
        return left; 
    } else {
        return right; 
    }
}

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size(); 
        vector<int> ans = prices; 
        stack<int> rr; 
        int ref; 

        // find and save the next low.  
        for (int i = 0; i < n; i++) {
            while (!rr.empty() && prices[i] <= prices[rr.top()]) {
                ref = rr.top(); 
                rr.pop(); 
                ans[ref] = prices[ref] - prices[i]; 
            }
            rr.push(i); 
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{

    vector<int> p1 = {8,4,6,2,3}; 
    vector<int> p2 = {1,2,3,4,5}; 
    vector<int> p3 = {10,1,1,6}; 

    Solution so;
    printArray(so.finalPrices(p1)); 
    cout << endl ; ; 

    printArray(so.finalPrices(p2)); 
    cout << endl ; ; 

    printArray(so.finalPrices(p3)); 
    cout << endl ; ; 

    return 0;

}
