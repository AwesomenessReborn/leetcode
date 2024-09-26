// https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=bit-manipulation

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
    int singleNumber(vector<int>& nums) {
        int cur = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            cur = cur ^ nums[i]; 
        }
        return cur; 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 
    std::vector<int> n1 = {2, 2, 1}; 
    std::vector<int> n2 = {4, 1, 2, 1, 2}; 
    std::vector<int> n3 = {1} ; 

    cout << sol.singleNumber(n1) << endl; 
    cout << sol.singleNumber(n2) << endl; 
    cout << sol.singleNumber(n3) << endl; 

    return 0;
}
