// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

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


struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

/**
 * use a stack to remember the numbers that are read in the tokens. 
 * 
 * if a operator found in token: 
 *      --> use the last 2 values in the stack to perform the operation, indicated by the operand. 
 * else: 
 *      (this should be a int value) --> push the new int value into stack.
 * 
 * 
 * by the end, there should only be a single value in the stack --> should be ans.  
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values; 
        
        int n1, n2, pot, sign; 
        for (string tok : tokens) {
            if (tok == "+") {
                n1 = values.top(); 
                values.pop(); 

                n2 = values.top(); 
                values.pop(); 

                values.push(n2 + n1); 
            } else if (tok == "-") {
                n1 = values.top(); 
                values.pop(); 

                n2 = values.top(); 
                values.pop(); 

                values.push(n2 - n1); 
            } else if (tok == "*") {
                n1 = values.top(); 
                values.pop(); 

                n2 = values.top(); 
                values.pop(); 

                values.push(n2 * n1); 
            } else if (tok == "/") {
                n1 = values.top(); 
                values.pop(); 

                n2 = values.top(); 
                values.pop(); 

                values.push(n2 / n1); 
            } else {
                // must be int value. 
                if (tok[0] == '-') {
                    sign = -1; 
                    tok = tok.substr(1); 
                } else {
                    sign = 1; 
                }

                pot = (int)(tok[0]-'0'); 
                for (int i = 1; i < tok.size(); i++) {
                    pot = (pot*10) + (int)(tok[i]-'0'); 
                }
                values.push(pot * sign); 
            }

        }

        return values.top(); // values should be size 1. 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
