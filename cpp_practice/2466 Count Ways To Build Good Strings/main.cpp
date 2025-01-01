// https://leetcode.com/problems/count-ways-to-build-good-strings/description/?envType=daily-question&envId=2024-12-30

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
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7; 

        vector<int> dp(high+1, 0);      // index 0 --> string size 0. 
                                        // index 1 --> string size 1. 
                                        // ....
        dp[0] = 1; 

        for (int i = 1; i <= high; i++) { // bottom to up dp solution
            // if (i == zero) dp[i] += 1; 
            // if (i == one) dp[i] += 1; 

            // if (i != zero && i - zero >= 1) dp[i] += dp[i-zero]; 
            // if (i != one && i - one >= 1) dp[i] += dp[i-one]; 
            if (i >= zero) {
                dp[i] += dp[i-zero]; 
                dp[i] %= MOD; 
            }
            if (i >= one) {
                dp[i] += dp[i-one]; 
                dp[i] %= MOD; 
            }
        }

        int res = 0; 
        for (int i = low; i <= high; i++) {
            res += dp[i]; 
            res %= MOD; 
        }
        
        return res; 
    }
};

int main(int argc, char const *argv[])
{
    const int MOD = 1e9 + 7; 

    Solution s; 

    cout << s.countGoodStrings(3, 3, 1, 1) << endl; 
    cout << endl; 
    cout << s.countGoodStrings(2, 3, 1, 2) << endl; 
    cout << endl; 

    return 0; 
}
