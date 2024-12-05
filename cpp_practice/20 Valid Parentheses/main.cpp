// https://leetcode.com/problems/valid-parentheses/

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

class Solution {
public:
    bool isValid(string s) {
        vector<char> stk; 

        for (char c : s) {
            switch (c)
            {
            case '(':
                stk.push_back('('); 
                break;

            case '{':
                stk.push_back('{'); 
                break;

            case '[':
                stk.push_back('['); 
                break;

            case ')': 
                if (stk.size() == 0) return false; 
                if (stk.back() != '(') return false; 
                stk.pop_back(); 
                
                break; 
            
            case '}': 
                if (stk.size() == 0) return false; 
                if (stk.back() != '{') return false; 
                stk.pop_back(); 

                break; 

            case ']': 
                if (stk.size() == 0) return false; 
                if (stk.back() != '[') return false; 
                stk.pop_back(); 

                break; 

            default:
                break;
            }
        }

        return stk.size() == 0; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
