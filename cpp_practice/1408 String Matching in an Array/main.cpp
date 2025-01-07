// https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07

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

// class Solution {
// private: 
//     /** 
//      * returns the substring of given two random strings, does not matter which is bigger than which in input. 
//      * returns "" if not substring. 
//      */
//     string retSub(string big, string small) {
//         if (big.size() == small.size()) return ""; 

//         if (big.size() < small.size()) {
//             swap(big, small); 
//         }

//         for (int i = 0; i < big.size(); i++) {

//             int j = 0; 
//             while (j < small.size() && big[i+j] == small[j]) j++; 

//             if (j == small.size()) {
//                 return small; 
//             }
//         }
        
//         return ""; 
//     }
// public:
//     vector<string> stringMatching(vector<string>& words) {
        
//         vector<string> res; 
//         unordered_set<int> used; 

//         for (int i = 0; i < words.size(); i++) {
//             for (int j = i+1; j < words.size(); j++) {
//                 if (used.count(i) || used.count(j)) continue;

//                 auto pot = retSub(words[i], words[j]); 
//                 if (pot != "") {
//                     if (pot == words[i]) {
//                         used.insert(i); 
//                     } else {
//                         used.insert(j); 
//                     }
//                     res.push_back(pot); 
//                 }

//             }
//         }

//         return res; 

//     }
// };

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res; 

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                if (i == j) continue;

                auto found = words[j].find(words[i]);
                if (found != string::npos) {
                    res.push_back(words[i]); 
                    break; 
                }
            }
        }

        return res; 
    }
};

int main() {

    vector<string> s1 = {
        "mass","as","hero","superhero"
    }; 
    vector<string> s2 = {
        "leetcode","et","code"
    }; 
    vector<string> s3 = {
        "blue","green","bu"
    }; 

    Solution s; 

    cout << "1. " << endl; 
    printArray(s.stringMatching(s1)); 
    cout << "2. " << endl; 
    printArray(s.stringMatching(s2)); 
    cout << "3. " << endl; 
    printArray(s.stringMatching(s3)); 

    return 0;   
}

