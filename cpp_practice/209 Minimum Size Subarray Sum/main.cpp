

#include <climits>
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

/**
 * 
 * if sum >= target: 
 *      move the slow pointer. 
 * else: 
 *      move the fast pointer. 
 */
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int len = INT_MAX;

        while(right < n)
        {
            sum = sum + nums[right];
            while(sum >= target)
            {
                len = min(len, right-left+1);
                sum = sum - nums[left];
                left++;
            }
            right++;
        }
        return len == INT_MAX ? 0 : len;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {
        2,3,1,2,4,3
    }; 
    vector<int> n2 = {
        1,4,4
    }; 
    vector<int> n3 = {
        1,1,1,1,1,1,1,1
    }; 

    Solution sol; 
    cout << sol.minSubArrayLen(7, n1) << endl; 
    cout << sol.minSubArrayLen(4, n2) << endl; 
    cout << sol.minSubArrayLen(11, n3) << endl; 

    return 0;
}
