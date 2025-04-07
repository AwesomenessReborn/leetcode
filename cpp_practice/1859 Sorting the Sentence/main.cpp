// https://leetcode.com/problems/sorting-the-sentence/

#include <map>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

template <typename T>
void printArray(std::vector<T> values)
{
    std::cout << "[";
    for (int i = 0; i < values.size(); i++)
    {
        std::cout << values[i];
        if (values.size() - 1 > i)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

class Solution {
public:
    string sortSentence(string s) {
        std::array<string, 9> ans; 

        int size = 0; 
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                ans[(s[i-1])-49] = string(s.substr(i-size, size-1)); 
                size = 0; 
            } else if (i == s.size() - 1) {
                ans[(s[i])-49] = string(s.substr(i-size, size)); 
            } else {
                size++; 
            }
        }
        std::vector<string> reee(ans.begin(), ans.end()); 
        printArray(reee); 
        
        string res; 
        for (string s : ans) {
            if (s.empty()) continue;
            res.append(s); 
            res.append(" "); 
        }
        res.pop_back(); 
        return res; 
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "is2 sentence4 This1 a3"; 
    string s2 = "Myself2 Me1 I4 and3"; 

    Solution sol; 

    string a1 = sol.sortSentence(s1); 
    string a2 = sol.sortSentence(s2); 
    cout << endl << "'" << a1 << "'" << endl; 
    cout << endl << "'" << a2 << "'" << endl; 

    return 0;
}
