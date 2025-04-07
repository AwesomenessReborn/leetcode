// https://leetcode.com/problems/plus-one/

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
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size()-1; 

        if (digits[n] != 9) {
            digits[n]++; return digits; 
        }
        while (n <= 0 && digits[n] == 9) {
            digits[n] = 0; n--; 
        }
        if (n < 0) {
            digits.insert(digits.begin(), 1); 
        } else {
            digits[n]++; 
        }

        return digits; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> t1 = {1,2,3}; 
    vector<int> t2 = {4,3,2,1}; 
    vector<int> t3 = {9}; 
    Solution sol; 

    printArray(sol.plusOne(t1)); 
    printArray(sol.plusOne(t2)); 
    printArray(sol.plusOne(t3)); 

    return 0;
}
