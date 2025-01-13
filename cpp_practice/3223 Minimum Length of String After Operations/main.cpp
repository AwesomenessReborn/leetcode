// https://leetcode.com/problems/minimum-length-of-string-after-operations/description/?envType=daily-question&envId=2025-01-13

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
// public:
//     int minimumLength(string s) {
//         int hash[26] = {0}; 

//         for (const char &c : s) {
//             hash[c-'a']++; 
//         }

//         int cc = 0; 
//         for (int i = 0; i < 26; i++) {
//             if (hash[i] <= 2) cc+= hash[i]; 
//             else {
//                 cc += (hash[i] % 2 == 1) ? 1 : 2; 
//             }
//         }

//         return cc; 
//     }
// };


class Solution {
public:
    int minimumLength(string s) {
        unsigned int presence = 0; // Tracks presence of characters
        unsigned int oddFrequency = 0; // Tracks whether frequency is odd

        for (char c : s) {
            int bit = c - 'a';
            presence |= (1 << bit); // Mark character as present
            oddFrequency ^= (1 << bit); // Toggle odd/even state for the character
        }

        // Calculate the minimum length based on odd frequencies
        int minLength = 0;
        for (int i = 0; i < 26; i++) {
            if (presence & (1 << i)) { // If character is present
                minLength += (oddFrequency & (1 << i)) ? 1 : 2;
            }
        }

        return minLength;
    }
};



int main() {
    string s1 = "abaacbcbb"; 
    string s2 = "aa"; 

    Solution s; 

    cout << s.minimumLength(s1) << endl; 
    cout << s.minimumLength(s2) << endl; 

    return 0;   
}
