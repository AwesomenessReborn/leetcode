// https://leetcode.com/problems/repeated-substring-pattern/description/

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
    bool repeatedSubstringPattern(string s) {

        for (int i = 1; i < s.size(); i++) {
            // i refers to substring size. 
            if (s.size() % i != 0) continue; 

            for (int b = 0; b < s.size(); b+=i) {
                if (s.substr(b, i) != s.substr(0, i)) break; 
                if (b+i >= s.size()) return true; 
            }
        }

        return false; 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 

    cout << sol.repeatedSubstringPattern("bb") << endl; 

    return 0;
}
