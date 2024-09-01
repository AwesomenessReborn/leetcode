// https://leetcode.com/problems/kth-distinct-string-in-an-array/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
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
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mapper; 

        for (string te : arr) {
            mapper[te]++; 
        }

        for (string te : arr) {
            if (mapper[te] == 1) {
                k--; 
                if (k == 0) return te; 
            }
        }

        return ""; 
    }
};

int main(int argc, char const *argv[])
{
    





    return 0;
}
