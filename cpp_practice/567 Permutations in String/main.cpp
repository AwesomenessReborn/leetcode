//https://leetcode.com/problems/permutation-in-string/description/?envType=problem-list-v2&envId=em7rav6v 

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
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false; 

        array<int, 26> refhash = {0}; 
        for (char c : s1) {
            refhash[c - 'a']++;
        }

        array<int, 26> cmp = {0}; 
        int beg = 0;
        int end = s1.size();  

        for (int i = 0; i < end; i++) {
            cmp[s2[i] - 'a']++;
        }

        while (end <= s2.size()) {
            if (std::equal(refhash.begin(), refhash.end(), cmp.begin())) {
                return true;
            }

            if (end < s2.size()) {
                cmp[s2[beg] - 'a']--;  
                cmp[s2[end] - 'a']++;  
            }

            beg++;
            end++;
        }

        return false;  
    }
};

int main(int argc, char const *argv[])
{


    return 0;
}
