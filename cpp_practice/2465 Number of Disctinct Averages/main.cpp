// https://leetcode.com/problems/number-of-distinct-averages/description/?envType=problem-list-v2&envId=two-pointers

#include <stack> 
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

template <typename T>
void printDoubleArray(std::vector<std::vector<T>> values) {
    cout << "[\n"; 
    for (int i = 0; i < values.size(); i++) {
        cout << "\t"; 
        printArray(values[i]); 
        if (i != values.size()-1) cout << ", "; 
    }
    cout << "]"; 
}

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); 

        int left = 0, right = nums.size()-1; 
        unordered_set<float> vals; 

        while (left < right) {
            vals.insert((float)(nums[left] + nums[right]) / 2); 
            left++; right--; 
        }

        return vals.size(); 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {
        9,5,7,8,7,9,8,2,0,7
    }; 

    Solution s; 

    cout << s.distinctAverages(n1) << endl; 

    return 0;
}