// https://leetcode.com/problems/decode-string/?envType=problem-list-v2&envId=a9a7jmom

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
    string decodeString(string s) {
        string ans; 
        
        int idx = 0; 
        vector<string> buff; 
        vector<int> values; 

        while (idx < s.size()) {

            if (isdigit(s[idx])) {
                int value = 0; 
                while (isdigit(s[idx])) {
                    value = (value*10) + (s[idx] - '0');
                    idx++;
                }
                values.push_back(value); 
                continue;
            } 

            if (s[idx] == '[') {
                buff.push_back(ans); 
                ans = ""; 
                idx++; 
            } else if (s[idx] == ']') {
                string temp = buff.back(); 
                buff.pop_back(); 
                int count = values.back(); 
                values.pop_back(); 
                for (int i = 0; i < count; i++) {
                    temp += ans; 
                }
                ans = temp; 
                idx++;
            } else {
                ans += s[idx++]; 
            }
        }

        return ans;  
    }
}; 

int main(int argc, char const *argv[])
{
    string s1 = "3[a]2[bc]"; 
    string s2 = "3[a2[c]]"; 
    string s3 = "2[abc]3[cd]ef"; 
    Solution sol; 
    
    cout << sol.decodeString(s1) << endl; 
    cout << sol.decodeString(s2) << endl; 
    cout << sol.decodeString(s3) << endl; 

    return 0;
}




/**
 * 
class Solution {
public:
    string decodeString(string s) {
        string ans = ""; 
        int cnt = 0; 
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                cnt = (cnt*10) + (s[i] - '0'); 
                continue;
            }
            if (s[i] == '[') {
                int end = i+1; 
                int cnt_open = 0; 
                while (cnt_open == 0 && s[end] != ']') {
                    cout << "current sub: " << s.substr(i+1, end-(i+1)) << endl; 
                    end++; 
                    if (s[end] == ']') {
                        cnt_open--; 
                        continue;
                    }
                    if (s[end] == '[') {
                        cnt_open++; 
                        continue;
                    }
                }
                cout << "ended -- end has been found: " << endl;  

                cout << "sub: " << s.substr(i+1, end-(i+1)) << "\t"; 
                cout << "cnt: " << cnt << endl; 

                string buff = decodeString(s.substr(i+1, end-(i+1))); 
                cout << "buff: " << buff << endl; 
                for (int r = 0; r < cnt; r++) {
                    ans += buff;
                }
                cnt = 0; 
                i+= (end-(i)); 
                continue;
            }
            ans += s[i]; 
        }

        return ans; 
    }
};

 */