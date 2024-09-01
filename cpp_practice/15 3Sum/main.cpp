// https://leetcode.com/problems/3sum/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

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
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::unordered_map<int, int> freqMap; 
        for (int num : nums) {
            freqMap[num]++; 
        }
        


    }
};

int main(int argc, char const *argv[])
{




    return 0;
}
