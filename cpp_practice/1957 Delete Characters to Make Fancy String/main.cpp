// https://leetcode.com/problems/delete-characters-to-make-fancy-string/?envType=daily-question&envId=2024-11-01

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
#include <stack>

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
    string makeFancyString(string s) {
        string res = ""; 

        bool twice = false; 
        char prev = '^'; 
        for (char c : s) {
            if (twice && c == prev) {
                continue;
            } else if (c == prev) {
                twice = true; 
                res += c; 
                continue;
            } else {
                res += c; 
                twice = false; 
            }

            prev = c; 
        }

        return res; 
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "leeetcode"; 
    string s2 = "aaabaaaa"; 
    string s3 = "aab"; 

    Solution sol; 

    cout << sol.makeFancyString(s1) << endl; 
    cout << sol.makeFancyString(s2) << endl; 
    cout << sol.makeFancyString(s3) << endl; 

    return 0;
}
