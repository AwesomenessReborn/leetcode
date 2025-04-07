// https://leetcode.com/problems/rotate-string/?envType=daily-question&envId=2024-11-12

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
    bool rotateString(string s, string goal) {
        string cmp = s+s; 

        int bu; 
        for (int i = 0; i < s.size(); i++) {
            bu = 0; 
            while (cmp[bu+i] == goal[bu]) {
                bu++; 
                if (bu >= s.size()) return true; 
            }
        }
        
        return false; 
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "abcde"; 
    string g1 = "cdeab"; 

    string s2 = "abcde"; 
    string g2 = "abced"; 

    Solution so; 
    cout << so.rotateString(s1, g1) << endl; 
    cout << so.rotateString(s2, g2) << endl; 

    return 0;

}
