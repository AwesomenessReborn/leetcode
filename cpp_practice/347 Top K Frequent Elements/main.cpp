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


/**
 * build frequency hash map, 
 * 
 * then heapify using second element, which should be frequency. 
 * 
 * use heap algorithms for <algorithm> header
 */
class Solution {
private: 
    static bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first > b.first;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == k) return nums; 

        vector<int> ans; 
        ans.reserve(k); 

        unordered_map<int, int> fmap;  // element -> frequency

        for (int value : nums) {
            fmap[value]++; 
        }

        vector<std::pair<int, int>> topk; // frequency -> element ... for frequency (min-heap)
        for (std::unordered_map<int, int>::iterator target = fmap.begin(); target != fmap.end(); ++target) {

            topk.push_back(std::make_pair(target->second, target->first)); 
            std::push_heap(topk.begin(), topk.end(), compare); 

            if (topk.size() > k) {
                std::pop_heap(topk.begin(), topk.end(), compare); 
                topk.pop_back(); 
            }
        }

        for (std::pair<int, int> rec : topk) {
            ans.push_back(rec.second); 
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
