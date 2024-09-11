// https://leetcode.com/problems/kth-largest-element-in-an-array/description/ 

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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::greater<int> > que;   // construct min heap; 

        for (int i = 0; i < nums.size(); i++) {
            que.push(nums[i]); 

            if (que.size() > k) {
                que.pop(); 
            }
        }

        return que.top(); 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 

    vector<int> n1 = {3,2,1,5,6,4}; 
    vector<int> n2 = {3,2,3,1,2,4,5,5,6}; 

    cout << sol.findKthLargest(n1, 2) << endl; ; 
    cout << sol.findKthLargest(n2, 4) << endl; ; 

    return 0;
}
