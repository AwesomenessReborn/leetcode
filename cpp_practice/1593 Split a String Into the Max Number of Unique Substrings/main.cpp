// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/?envType=daily-question&envId=2024-10-21

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

/**
 * alg: 
 * 
 * create set. 
 * 
 * backtrack--find solutions: 
 * 
 * find_sol(): 
 *      
 *      add len(1) into set. 
 *          if (find_sol(substr(1))) (with given input set. ) 
 *               return find(sol(substr(2))); 
 *          --- need to explore until end of string. 
 *           >> else return false; 
 */

class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> ss; 
        return backtrack(s, 0, ss); 
    }
private: 
    int backtrack(const string& s, int begin, unordered_set<string> &ss) {
        if (begin == s.size()) return 0; // check if we at the end of string 

        int maxSplits = 0;  // keep track of # of splits we making
        for (int i = begin+1; i <= s.size(); i++) {
            string leftover = s.substr(begin, i-begin); 
            if (ss.find(leftover) == ss.end()) {
                ss.insert(leftover); 
                maxSplits = max(maxSplits, 1+backtrack(s, i, ss));  // keep track of the largest path. 
                ss.erase(leftover);  // we can keep on finding and searching multiple paths. 
            }
        }

        return maxSplits;  
    }
};

int main(int argc, char const *argv[])
{
    string s1 = ""; 
    string s2 = ""; 
    string s3 = ""; 

    Solution sol; 

    cout << sol.maxUniqueSplit(s1) << endl; 
    cout << sol.maxUniqueSplit(s2) << endl; 
    cout << sol.maxUniqueSplit(s3) << endl; 

    return 0;
}
