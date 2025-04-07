// https://leetcode.com/problems/removing-stars-from-a-string/?envType=study-plan-v2&envId=leetcode-75

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
    string removeStars(string s) {
        vector<char> stack; 

        for (char c : s) {
            if (c == '*') {
                stack.pop_back(); 
            } else {
                stack.push_back(c); 
            }
        }

        string ans; 
        for (char c : stack) {
            ans.push_back(c) ; 
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{
    string n1 = "leet**cod*e"; 
    string n2 = "erase*****"; 
    Solution sol; 
    cout << sol.removeStars(n1) << endl; 
    cout << sol.removeStars(n2) << endl; 

    return 0;
}
