

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
            std::cout << ", " << std::cou
        }
    }
    std::cout << "]" << std::endl; 
}

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res; 
        res.reserve(nums.size())        ; 
        int cur =0; 
        for (int i = 0; i < nums.size(); i++) {
            cur += nums[i]; 
            // res[i] = cur; 
            res.push_back(cur); 
        }
        return res; 
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
