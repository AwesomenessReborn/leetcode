// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std; 

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
    int strStr(string haystack, string needle) {
        int tracked = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[tracked]) {
                tracked++;
                if (tracked == needle.size())
                {
                    return i - tracked + 1;
                }
            } else {
                i -= tracked; 
                tracked = 0;
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 

    string h = "hello"; 
    string n = "ll"; 

    string h2 = "mississippi"; 
    string n2 = "issip"; 

    cout << sol.strStr(h, n) << endl;  
    cout << sol.strStr(h2, n2) << endl;  

    return 0;
}
