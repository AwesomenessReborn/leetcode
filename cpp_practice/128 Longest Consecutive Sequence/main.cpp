// https://leetcode.com/problems/longest-consecutive-sequence/description/

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
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; 

        int longest = 0; 
        int counter, value; 

        unordered_set<int> rec(nums.begin(), nums.end()); 

        for (int i = 0; i < nums.size(); i++) {
            /**
             * only make a measurement if: 
             *      1. if beginning of the consecutive elements. 
             *      2. if even found in set. 
             * 
             * make sure to: 
             *      1. remove elements after measurement was taken. 
             */
            value = nums[i]; 
            auto it = rec.find(value); 
            if (it == rec.end()) continue; 
            if (rec.find(value - 1) != rec.end()) continue;

            // now we know conditions passed, perform measurement. 
            counter = 1; 
            rec.erase(value);
            value++; 
            it = rec.find(value); 
            while (it != rec.end()) {
                value++;
                counter++; 
                rec.erase(it); 
                it = rec.find(value); 
            } 

            longest = std::max(counter, longest); 
        }

        return longest; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {100,4,200,1,3,2}; 
    vector<int> n2 = {0,3,7,2,5,8,4,6,0,1}; 

    Solution sol; 

    cout << sol.longestConsecutive(n1) << endl; 
    cout << "actual: 4" << endl; 

    cout << sol.longestConsecutive(n2) << endl; 
    cout << "actual: 9" << endl; 

    return 0;
}
