// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/?envType=daily-question&envId=2025-01-04

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

struct ArrayHash {
    std::size_t operator()(const std::array<char, 3>& arr) const {
        std::size_t hash = 0;
        for (int num : arr) {
            hash ^= std::hash<char>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int n = s.size(); 
        int cc = 0; 
        unsigned int hh; 

        for (char pc = 'a'; pc != '{'; pc++) {
            int l = 0, r = n-1; 

            while (l < n && s[l] != pc) l++; 
            while (r >= 0 && s[r] != pc) r--; 

            if (l >= r || s[l] != pc || s[r] != pc) {
                continue;  // cannot make palindrome 
            }
            // otherwise, it seems that they are valid bounds, palindrome possible. 
            if (r - l > 1) {
                hh = 0; 
                
                for (int chk = l+1; chk < r; chk++) {
                    if (hh & (1 << (s[chk] - 97))) {
                        continue;
                    } else {
                        cc++; 
                        hh |= (1 << (s[chk] - 97)); 
                    }
                }
            }
        }

        return cc;
    }
};

int main() {
    string s1 = "aabca"; 
    string s2 = "adc"; 
    string s3 = "bbcbaba"; 

    Solution s; 

    cout << s.countPalindromicSubsequence(s1) << endl; 
    cout << "expected 3\n" << endl; 

    cout << s.countPalindromicSubsequence(s2) << endl; 
    cout << "expected 0\n" << endl; 

    cout << s.countPalindromicSubsequence(s3) << endl; 
    cout << "expected 4\n" << endl; 

    return 0;   
}
