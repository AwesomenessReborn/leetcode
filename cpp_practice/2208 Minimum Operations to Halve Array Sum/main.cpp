// https://leetcode.com/problems/minimum-operations-to-halve-array-sum/

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
 * create max priority que: 
 * for every max -- reduce and recalculate sum; 
 */

class Solution {
public:
    int halveArray(vector<int>& nums) {
        float sum = 0;         
        priority_queue<float, vector<float>> que; 
        for (float value : nums) {
            sum += value; 
            que.push(value); 
        }
        float half = sum / 2; 
        int cnt = 0; 
        while (half <= sum) {
            cnt++; 
            float hv = (float)que.top(); 
            que.pop(); 
            sum = sum - hv + (hv/2); 
            que.push((hv/2));
        }
        return cnt; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {5,19,8,1}; 
    vector<int> n2 = {3,8,20}; 

    Solution sol; 

    cout << sol.halveArray(n1) << endl; 
    cout << sol.halveArray(n2) << endl; 

    return 0;
}
