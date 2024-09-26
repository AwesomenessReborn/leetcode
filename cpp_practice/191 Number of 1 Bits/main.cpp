// https://leetcode.com/problems/number-of-1-bits/description/?envType=problem-list-v2&envId=bit-manipulation

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
    int hammingWeight(int n) {
        int cnt=0; 
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 0x1) cnt++; 
        }
        return cnt; 
    }
};

int main(int argc, char const *argv[])
{
    int n1 = 11; 
    int n2 = 128; 
    int n3 = 2147483645; 

    Solution sol; 
    cout << sol.hammingWeight(n1) << endl; 
    cout << sol.hammingWeight(n2) << endl; 
    cout << sol.hammingWeight(n3) << endl; 

    return 0;
}
