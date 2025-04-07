// https://leetcode.com/problems/climbing-stairs/

#include <map>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

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
    int climbStairs(int n) {
        int one = 1; 
        int two = 1; 

        if (n == 1) return 1; 
        if (n == 2) return 2; 

        int idx=2; 
        while (idx < n) {

            int tmp = one; 
            one = one + two; 
            two = tmp; 
            idx++; 
        }

        return one+two; 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 
    for (int i = 1; i < 6; i++) {
        cout << sol.climbStairs(i) << endl; 
    }

    return 0;
}
