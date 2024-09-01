// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-04

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> t; 

        for (int i = 0; i < target.size(); i++) {
            std::pair<std::unordered_map<int, int>::iterator, bool> res = t.insert(std::make_pair(target[i], 1)); 
            if (!res.second) {
                res.first->second++; 
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            if (--t[arr[i]] < 0) {
                return false; 
            }
        }

        return true; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> t1 = {1, 2, 3, 4}; 
    vector<int> a1 = {2,4,1,3}; 

    vector<int> t2 = {7}; 
    vector<int> a2 = {7}; 

    vector<int> t3 = {3,7,9}; 
    vector<int> a3 = {3,7,11}; 

    Solution sol; 

    cout << sol.canBeEqual(t1, a1) << endl; 
    cout << sol.canBeEqual(t2, a2) << endl; 
    cout << sol.canBeEqual(t3, a3) << endl; 

    return 0;
}
