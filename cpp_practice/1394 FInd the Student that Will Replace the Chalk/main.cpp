// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/?envType=daily-question&envId=2024-09-02

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
    int chalkReplacer(vector<int>& chalk, int k) {
        // vector<int> csum; 
        int sum = 0; 
        // csum.push_back(chalk[0]); 
        for (int i = 0; i < chalk.size(); i++) {
            // csum.push_back(chalk[i] + csum[i-1]); 
            sum += chalk[i]; 
        }
        // printArray(csum); 

        int leftover = k % sum; 
        cout << "leftover: " << leftover << endl; 
        int idx = 0; 
        while (leftover >= chalk[idx]) {
            leftover -= chalk[idx++]; 
        }
        return idx; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> c1 = {5,1,5}; 
    vector<int> c2 = {3,4,1,2}; 
    Solution sol; 
    
    cout << sol.chalkReplacer(c1, 22) << endl; 
    cout << sol.chalkReplacer(c2, 25) << endl; 

    return 0;
}
