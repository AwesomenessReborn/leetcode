// https://leetcode.com/problems/fibonacci-number/

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
    int fib(int n) {
        vector<int> rec; 
        int idx = 0; 

        while (idx < n) {
            if (idx == 0 || idx == 1) {
                rec.push_back(1); 
                idx++;  
                continue; 
            }
            rec.push_back(rec[rec.size()-1] + rec[rec.size()-2]); 
            idx++; 
        }
        return rec[n-1]; 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 
    
    for (int i=1; i < 6; i++) {
        cout << sol.fib(i) << endl; 
    }

    return 0;
}
