// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/?envType=problem-list-v2&envId=dynamic-programming

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
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        if (n == 0 || groups.size() != n) return {};

        int fone = -1, fzero = -1;

        for (int i = 0; i < n; i++) {
            if (groups[i] == 1 && fone == -1) fone = i;
            if (groups[i] == 0 && fzero == -1) fzero = i;
            if (fone != -1 && fzero != -1) break;
        }

        if (fone == -1) return collectSubsequence(words, groups, fzero);
        if (fzero == -1) return collectSubsequence(words, groups, fone);

        int s1 = calculateLength(words, groups, fone);
        int s0 = calculateLength(words, groups, fzero);

        if (s1 > s0) return collectSubsequence(words, groups, fone);
        return collectSubsequence(words, groups, fzero);
    }

private:
    int calculateLength(vector<string>& words, vector<int>& groups, int idx) {
        int n = words.size();
        int totalLength = 0;
        int prevGroup = -1;

        while (idx < n) {
            totalLength += words[idx].size();
            prevGroup = groups[idx];
            idx++;
            while (idx < n && groups[idx] == prevGroup) idx++;
        }

        return totalLength;
    }

    vector<string> collectSubsequence(vector<string>& words, vector<int>& groups, int idx) {
        int n = words.size();
        vector<string> subsequence;
        int prevGroup = -1;

        while (idx < n) {
            subsequence.push_back(words[idx]);
            prevGroup = groups[idx];
            idx++;
            while (idx < n && groups[idx] == prevGroup) idx++;
        }

        return subsequence;
    }
};


// class Solution {
// public:
//     vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
//         int fone=-1, fzero=-1; 
//         int n = words.size(); 
        
//         for (int i = 0; i < n; i++) {
//             if (fone != -1 && fzero != -1) break; // found both begins. 

//             if (fone == -1) {
//                 if (groups[i] == 1) fone = i; 
//             }

//             if (fzero == -1) {
//                 if (groups[i] == 0) fzero = i; 
//             }
//         }

//         int s1 = 0, s0 = 0; 
//         int idx = fone; 
//         int prev; 
//         while (idx < n) {
//             s1 += words[idx].size(); 

//             prev = groups[idx]; 
//             idx++; 
//             while (idx < n && prev == groups[idx]) idx++; 
//         }

//         idx = fzero; 
//         while (idx < n) {
//             s0 += words[idx].size(); 

//             prev = groups[idx]; 
//             idx++; 
//             while (idx < n && prev == groups[idx]) idx++; 
//         }

//         vector<string> res; 
//         if (s1 > s0) {
//             idx = fzero; 
//             while (idx < n) {
//                 res.push_back(words[idx]); 

//                 prev = groups[idx]; 
//                 idx++; 
//                 while (idx < n && prev == groups[idx]) idx++; 
//             }
            
//             return res; 
//         }

//         idx = fone; 
//         while (idx < n) {
//             res.push_back(words[idx]); 

//             prev = groups[idx]; 
//             idx++; 
//             while (idx < n && prev == groups[idx]) idx++; 
//         }
        
//         return res; 
//     }
// };

int main(int argc, char const *argv[])
{
    vector<string> w1 = {"e","a","b"}; 
    vector<string> w2 = {"a","b","c","d"}; 

    vector<int> g1 = {0,0,1}; 
    vector<int> g2 = {1,0,1,1}; 

    Solution s; 

    printArray(s.getLongestSubsequence(w1, g1)); 
    printArray(s.getLongestSubsequence(w2, g2)); 

    return 0;
}
