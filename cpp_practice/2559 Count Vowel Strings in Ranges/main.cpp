// https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02

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

class Solution {
private: 
    bool validate(char l) {
        return l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u'; 
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        const int qn = queries.size(), n = words.size(); 
        vector<int> ans(qn); 

        int cc = 0; 
        vector<int> acc(n); 
        for (int i = 0; i < n; i++) {
            if (validate(words[i][0]) && validate(words[i][words[i].size()-1])) {
                cc++; 
            }
            acc[i] = cc; 
        }

        for (int i = 0; i < qn; i++) {
            if (queries[i][0] == 0) {
                ans[i] = acc[queries[i][1]]; 
                continue;
            }
            ans[i] = acc[queries[i][1]] - acc[queries[i][0] - 1]; 
        }

        return ans; 
    }
};

int main() {
    
    Solution s; 
    vector<string> w1 = {
        "aba","bcb","ece","aa","e"
    }; 
    vector<string> w2 = {
        "a","e","i"
    }; 

    vector<vector<int>> q1 = {
        {0,2}, {1,4}, {1,1}
    }; 
    vector<vector<int>> q2 = {
        {0,2}, {0,1}, {2,2}
    }; 

    printArray(s.vowelStrings(w1, q1)); 
    printArray(s.vowelStrings(w2, q2)); 

    return 0;   
}

