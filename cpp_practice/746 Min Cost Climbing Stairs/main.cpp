// https://leetcode.com/problems/min-cost-climbing-stairs/?envType=problem-list-v2&envId=dynamic-programming

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

template <typename T>
void printDoubleArray(std::vector<std::vector<T>> values) {
    cout << "[\n"; 
    for (int i = 0; i < values.size(); i++) {
        cout << "\t"; 
        printArray(values[i]); 
        if (i != values.size()-1) cout << ", "; 
    }
    cout << "]"; 
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

/**
 * no backtracking. 
 * 
 * use dfs. 
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        vector<int> red(n, 0);
        red[n-1] = cost[n-1]; 
        red[n-2] = cost[n-2]; 

        for (int i = cost.size() - 3; i >= 0; i--) {
            red[i] = cost[i] + std::min(red[i+1], red[i+2]); 
        }

        return std::min(red[0], red[1]); 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {10,15,20}; 
    vector<int> n2 = {1,100,1,1,1,100,1,1,100,1}; 

    Solution s; 

    cout << s.minCostClimbingStairs(n1) << endl; 
    cout << s.minCostClimbingStairs(n2) << endl; 

    return 0;
}
