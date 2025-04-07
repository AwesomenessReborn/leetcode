
#include <map>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0]; 
        int idx = 0; 
        
        while (1) { 
            if (idx >= strs[0].size()) { 
                return strs[0].substr(0, idx); 
            } 
            char cur = strs[0].at(idx); 
            for (int i = 1; i < strs.size(); i++) { 
                if (idx >= strs[i].size()) { 
                    return strs[0].substr(0, idx); 
                }
                if (cur != strs[i].at(idx)) {
                    return strs[0].substr(0, idx); 
                }
            }

            idx++; 
        }

        return strs[0].substr(0, idx); 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 

    vector<string> s1 = {
        "ab", "a"
    }; 

    cout << sol.longestCommonPrefix(s1) << endl; 


    return 0;
}
