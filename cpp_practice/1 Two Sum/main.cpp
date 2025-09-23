

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
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rec; 
        vector<int> ans;  

        for (int i = 0; i < nums.size(); i++) {
            auto pot = rec.find(target - nums[i]); 
            if (pot != rec.end()) {
                ans.push_back(i); 
                ans.push_back(pot->second); 

                return ans; 
            }
            rec.insert(std::make_pair(nums[i], i)); 
        }
        return ans; 
    }
};

int main(int argc, char const *argv[])
{
	


    return 0;

}
