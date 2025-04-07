// https://leetcode.com/problems/merge-intervals/

#include <map>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>
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
            std::cout << ", "; 
        }
    }
    std::cout << "]" << std::endl; 
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end()); 

        vector<vector<int>> merged; 

        merged.push_back(intervals[0]); 
        for (int i = 1; i < intervals.size(); i++) {
            if (merged.back()[1] > intervals[1][0]) {
                merged.back()[1] = max(intervals[1][1], merged.back()[1]); 
            } else {
                merged.push_back(intervals[i]); 
            }
        }
        return merged; 
    }
};

int main(int argc, char const *argv[])
{



    return 0;
}
