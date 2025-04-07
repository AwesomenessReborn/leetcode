// https://leetcode.com/problems/maximum-product-after-k-increments/

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

struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}


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
 * for k times: 
 *      inc all the 0s first. 
 *      then: 
 *          do the least values: 
 * 
 * populate min heap: 
 *      replace every element with (i+1)
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end(), std::greater<int>());
        const int MOD = 1e9 + 7; 

        for (int i = 0; i < k; i++) {
            int tmp = nums[0]; 
            tmp++; 
            std::pop_heap(nums.begin(), nums.end(), std::greater<int>()); 
            nums.pop_back(); 
            nums.push_back(tmp); 
            std::push_heap(nums.begin(), nums.end(), std::greater<int>()); 
        }

        long long p = nums[0]; 
        for (int i = 1; i < nums.size(); i++) {
            p = (p * nums[i]) % MOD; 
        }
        return p; 
    }
};

int main(int argc, char const *argv[])
{

    Solution sol; 
    vector<int> n1 = {24,5,64,53,26,38}; 

    cout << "max prod: " << sol.maximumProduct(n1, 54) << endl;  

    return 0;
}
