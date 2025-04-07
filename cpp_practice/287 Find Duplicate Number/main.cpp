// https://leetcode.com/problems/find-the-duplicate-number/description/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std; 

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
    int findDuplicate(vector<int>& nums) {
        int fastidx = 0; 
        int slowidx = 0; 

        while (true) {
            slowidx = nums[slowidx]; 
            fastidx = nums[nums[fastidx]]; 
            if (slowidx == fastidx) break; 
        }

        int measure = 0; 
        while (fastidx != measure) {
            slowidx = nums[slowidx]; 
            measure = nums[measure]; 
            if (slowidx == measure) return measure; 
        }
        return -1; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1  = {1,3,4,2,2} ;
    vector<int> n2  = {3,1,3,4,2} ;
    vector<int> n3  = {3,3,3,3,3} ;

    Solution sol; 

    cout << sol.findDuplicate(n1) << endl;
    cout << sol.findDuplicate(n2) << endl;
    cout << sol.findDuplicate(n3) << endl;

    return 0;
}
