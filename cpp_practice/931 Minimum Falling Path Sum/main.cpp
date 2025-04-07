// https://leetcode.com/problems/minimum-falling-path-sum/description/

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
#include <climits>
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


class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        if (n == 1) return matrix[0][0];

        vector<int> p_dp(n), dp(n);

        for (int row = 0; row < n; row++) {
            if (row == 0) {
                p_dp = matrix[row]; 
                continue;
            }

            for (int col = 0; col < n; col++) {
                if (col == 0) {
                    // Left value doesn't exist.
                    dp[col] = matrix[row][col] + std::min(p_dp[col], p_dp[col + 1]);
                } else if (col == n - 1) {
                    // Right value doesn't exist.
                    dp[col] = matrix[row][col] + std::min(p_dp[col - 1], p_dp[col]);
                } else {
                    dp[col] = matrix[row][col] + std::min(p_dp[col - 1], std::min(p_dp[col], p_dp[col + 1]));
                }
            }

            p_dp = dp;

            // printArray(p_dp);
            // printArray(dp);
            // cout << endl;
        }

        int minSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            minSum = std::min(dp[i], minSum);
        }

        return minSum;
    }
};

int main() {

    
    return 0;   
}
