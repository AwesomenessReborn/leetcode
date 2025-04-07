

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

struct ArrayHash {
    std::size_t operator()(const std::array<int, 26>& arr) const {
        std::size_t hash = 0;
        for (int num : arr) {
            hash ^= std::hash<int>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::array<int, 26>, int, ArrayHash> locator;

        vector<vector<string>> ans; 

        for (string str : strs) {
            std::array<int, 26> cur = getHash(str); 

            auto target = locator.find(cur); 
            if (target == locator.end()) {
                locator.insert(std::make_pair(cur, ans.size())); 
                ans.push_back({}); 
                ans[ans.size()-1].push_back(str); 
            } else {
                ans[target->second].push_back(str); 
            }
        }

        return ans; 
    }
private: 

    std::array<int, 26> getHash(string str) {
        std::array<int, 26> hash = {0}; 

        for (char c : str) {
            hash[(int)(c-'a')]++; 
        }

        return hash; 
    }

};

int main(int argc, char const *argv[])
{

    return 0;
}
