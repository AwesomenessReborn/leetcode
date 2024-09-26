// https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=bit-manipulation

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

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0; 
        for (int i = 0; i < 32; i++) {
            int tmp = (n >> i) & 0x01; 
            res = (res << 1) | tmp; 
        }
        return res; 
    }
};

int main(int argc, char const *argv[])
{
    int n1 = 0b00000010100101000001111010011100; 
    int n2 = 0b11111111111111111111111111111101; 

    Solution sol; 

    cout << sol.reverseBits(n1) << endl; 
    cout << sol.reverseBits(n2) << endl; 

    return 0;
}
