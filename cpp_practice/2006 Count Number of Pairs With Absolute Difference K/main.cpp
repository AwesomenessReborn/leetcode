//  https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/

#include <map>
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
    int countKDifference(vector<int>& nums, int k) {
        int n = 0; 
        for (int j = 0; j < nums.size(); j++) {
            for (int i = j+1; i < nums.size(); i++) {
                if (abs(nums[i] - nums[j]) == k) n++; 
            }
        }
        return n; 
    }
};

int main(int argc, char const *argv[])
{



    return 0;
}
