// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=problem-list-v2&envId=eeyho3um

#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

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
    int minSteps(string s, string t) {
        array<int, 26> shash = {}; 
        array<int, 26> thash = {}; 

        for (char c : s) {
            shash[c-'a']++; 
        }
        for (char c : t) {
            thash[c-'a']++; 
        }

        int diff = 0; 

        for (int i = 0; i < 26; i++ ) {
            diff += abs(shash[i] - thash[i]); 
        }

        return diff / 2; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
