// https://leetcode.com/problems/sentence-similarity-iii/?envType=daily-question&envId=2024-10-06

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
    bool areSentencesSimilar(string sentence1, string sentence2) {
        
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 

    cout << (sol.areSentencesSimilar("My name is Haley", "My Haley") ? "true" : "false") << endl; 
    cout << "expected: true" << endl; 
    cout << (sol.areSentencesSimilar("of", "A lot of words") ? "true" : "false") << endl; 
    cout << "expected: false" << endl; 
    cout << (sol.areSentencesSimilar("Eating right now","Eating") ? "true" : "false") << endl; 
    cout << "expected: true" << endl; 

    return 0;
}
