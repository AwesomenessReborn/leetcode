// https://leetcode.com/problems/number-of-segments-in-a-string/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std; 

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

class Solution {
public:
    int countSegments(string s) {

        int idx=0; 
        int cnt=0; 
        while (idx < s.size()) {
            if (s[idx] != ' ') {
                // we are in a word: 
                while (idx < s.size() && s[idx] != ' ') idx++; 
                cnt++; 
            }
            idx++; 
        }

        return cnt; 
    }
};