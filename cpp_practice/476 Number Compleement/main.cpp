// https://leetcode.com/problems/number-complement/?envType=problem-list-v2&envId=eofbf01i

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

class Solution {
public:
    int findComplement(int num) {
        int lead = 31; 
        while (!((1 << lead) & num)) lead--; 
    
        int mask = 0; 
        for (int i = 0; i <= lead; i++) {
            mask |= (1 << i); 
        }

        return (~num) & mask; 
    }
};

int main(int argc, char const *argv[])
{
    int n1 = 5; 
    int n2 = 1; 
    int n3 = 2147483647; 

    Solution sol; 
    cout << "R1:  " << sol.findComplement(n1) << endl; 
    cout << "R2:  " << sol.findComplement(n2) << endl; 
    cout << "R3:  " << sol.findComplement(n3) << endl; 

    return 0;
}
