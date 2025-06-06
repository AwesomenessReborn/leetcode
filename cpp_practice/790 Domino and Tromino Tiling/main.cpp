// https://leetcode.com/problems/domino-and-tromino-tiling/

#include <numeric>
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

bool check(char pot) {
    return pot == 'a' || pot == 'e' || pot == 'i' || pot == 'o' || pot == 'u'; 
}


vector<vector<int>> solution(vector<vector<int>> a) {
    const int n = a.size(); 
    
    unordered_map<int, vector<int>> coll; 

    for (int group = 0; group < n; group++) {
        float mean = std::accumulate(a[group].begin(), a[group].end(), 0) / a[group].size(); 

        coll[mean].push_back(group); 
    }

    vector<vector<int>> res; 
    for (auto pp : coll) {
        vector<int> cur; 

        for (auto value : pp.second) {
            cur.push_back(value); 
        }

        res.push_back(cur); 
    }

    return res; 
}

// rule: A[N] = A[N-1] * 2 + A[N-3]
/**
 *this is some text kld;ja
 *this is some text l;kdasa
 *this is some text lkjasdf
 *this is some text lkja;df
 *this is some text klajdf
 * 
 */
class Solution {
public:
    const int MOD = 1e9 + 7; 

    int numTilings(int n) {
        vector<long long> dp(n + 1);
        if (n == 1) return 1; 
        if (n == 2) return 2; 
        if (n == 3) return 5; 
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i < n+1; i++) {
            dp[i] = ((dp[i-1]*2)%MOD + dp[i-3]%MOD) % MOD; 
        }

        return dp[n]; 
    }
};

int main() {
    string s = "this"; 

    return 0;
}