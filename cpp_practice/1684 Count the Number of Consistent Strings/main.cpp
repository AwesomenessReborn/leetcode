// https://leetcode.com/problems/count-the-number-of-consistent-strings/?envType=daily-question&envId=2024-09-12

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

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        array<bool, 26> alhash = {false}; 
        for (char c : allowed) {
            alhash[c - 'a'] = true; 
        }
        
        int cnt = 0; 
        for (string word : words) {
            bool valid = true; 
            for (char c : word) {
                if (!alhash[c-'a']) {
                    valid = false; 
                    break; 
                }
            }
            cnt = (valid) ? cnt+1 : cnt; 

        }
        return cnt; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
