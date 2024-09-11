// https://leetcode.com/problems/top-k-frequent-elements/?envType=problem-list-v2&envId=ee1sb8l6

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
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fmap; 

        for (int value : nums) {
            fmap[value]++; 
        }

        vector<std::pair<int, int>> rfmap; 
        for (auto it = fmap.begin(); it != fmap.end(); ++it) {
            rfmap.push_back(std::make_pair(it->second, it->first)); 
        }

        std::make_heap(rfmap.begin(), rfmap.end(), [](pair<int, int> ff, pair<int, int> ss){
            return ff.first < ss.first; 
        }); 

        vector<int> ans; 
        for (int i = 0; i < k; i++) {
            ans.push_back(rfmap[0].second); 
            pop_heap(rfmap.begin(), rfmap.end()); 
            rfmap.pop_back(); 
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {3,0,1,0}; 
    Solution sol; 

    auto a1 = sol.topKFrequent(n1, 1); 
    printArray(a1); 

    return 0;
}
