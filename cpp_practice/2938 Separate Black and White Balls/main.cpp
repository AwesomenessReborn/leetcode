// https://leetcode.com/problems/separate-black-and-white-balls/

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

// black -- 1
// white -- 0 
// move black (1) to the RIGHT and white (0) to the LEFT. 
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0; 
        int cnt = 0; 

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                ans += (long long)cnt; 
            } else {
                cnt++;
            }
        }
        
        return ans; 
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "101"; 
    string s2 = "100"; 
    string s3 = "0111"; 
    Solution sol; 

    cout << sol.minimumSteps(s1) << endl; 
    cout << sol.minimumSteps(s2) << endl; 
    cout << sol.minimumSteps(s3) << endl; 

    return 0;
}
