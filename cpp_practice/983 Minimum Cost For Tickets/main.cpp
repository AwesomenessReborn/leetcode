// https://leetcode.com/problems/minimum-cost-for-tickets/description/?envType=daily-question&envId=2024-12-31

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
#include <climits>

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

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(); 

        vector<int> dp(n, 0); 
        
        dp[n-1] = std::min(costs[0], std::min(costs[1], costs[2])); 

        int a, b, c, offset; 
        for (int i = n-2; i >= 0; i--) {
            
            a = costs[0] + dp[i+1]; 

            offset = 0; 
            while ((i+offset < n) && days[i+offset] - days[i] < 7) offset++; 
            b = (i + offset < n) ? costs[1] + dp[i+offset] : costs[1]; 
            
            offset = 0; 
            while ((i+offset < n) && days[i+offset] - days[i] < 30) offset++; 
            c = (i + offset < n) ? costs[2] + dp[i+offset] : costs[2]; 

            dp[i] = std::min(a, std::min(b, c));
        }
        // printArray(dp); 

        return dp[0]; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> d1 = {1,4,6,7,8,20}; 
    vector<int> d2 = {1,2,3,4,5,6,7,8,9,10,30,31}; 
    vector<int> d3 = {1,2,3,4,6,8,9,10,13,14,16,17,19,21,24,26,27,28,29}; 

    vector<int> c1 = {2,7,15}; 
    vector<int> c2 = {2,7,15}; 
    vector<int> c3 = {3,14,50}; 

    Solution s; 

    // cout << s.mincostTickets(d1, c1) << endl; 
    // cout << "should be 11." << endl; 
    // cout << endl; 

    // cout << s.mincostTickets(d2, c2) << endl; 
    // cout << "sould be 17. " << endl; 
    // cout << endl; 

    cout << s.mincostTickets(d3, c3) << endl; 
    cout << "sould be 50. " << endl; 
    cout << endl; 

    return 0;
}
