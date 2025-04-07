// https://leetcode.com/problems/product-of-array-except-self/description/

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


struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> ans(nums.size(), 1); 

        int acc = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = ans[i]*acc; 
            acc *= nums[i]; 
        }

        int acc = nums[nums.size()-1]; 
        for (int i = nums.size()-2; i >= 0; i++) {
            ans[i] = ans[i]*acc; 
            acc *= nums[i]; 
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
