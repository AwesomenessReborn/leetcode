// https://leetcode.com/problems/word-subsets/description/?envType=problem-list-v2&envId=eeyho3um

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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        array<int, 26> letcounter_max = {}; 
        array<int, 26> letcounter_cur; 
        
        for (string word : words2) {
            letcounter_cur.fill(0); 
            for (size_t i = 0; i < word.size(); i++)
            {
                letcounter_cur[(word[i])-'a']++; 
            }
            for (int i = 0; i < 26; i++) {
                letcounter_max[i] = max(letcounter_cur[i], letcounter_max[i]); 
            }
        }
        vector<string> ans; 
        for (string word : words1) {
            letcounter_cur.fill(0); 
            for (int i = 0; i < word.size(); i++) {
                letcounter_cur[(word[i])-'a']++; 
            }
            for (int i = 0; i < 26; i++) {
                if (letcounter_cur[i] < letcounter_max[i]) continue;
            }
            ans.push_back(word); 
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
