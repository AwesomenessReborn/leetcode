// https://leetcode.com/problems/last-stone-weight/description/

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
    int lastStoneWeight(vector<int>& stones) {
        std::make_heap(stones.begin(), stones.end()); 

        while (stones.size() > 1) {
            std::pop_heap(stones.begin(), stones.end()); 
            int first = stones.back(); 
            stones.pop_back(); 

            std::pop_heap(stones.begin(), stones.end()); 
            int second = stones.back(); 
            stones.pop_back(); 

            if (first != second) {
                stones.push_back(first-second); 
                std::push_heap(stones.begin(), stones.end()); 
            }
        }
        if (stones.size() == 1) return stones[0]; 
        return 0; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {2,7,4,1,8,1};
    vector<int> n2 = {1};
    Solution sol; 

    cout << sol.lastStoneWeight(n1) << endl; 
    cout << sol.lastStoneWeight(n2) << endl; 

    return 0;
}
