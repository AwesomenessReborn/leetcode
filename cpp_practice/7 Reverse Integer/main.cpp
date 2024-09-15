// https://leetcode.com/problems/reverse-integer/

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
    int reverse(int x) {
        int ans = 0; 

        while (x != 0) {
            int t_digit = x % 10; 
            
            if (ans > INT32_MAX / 10 || (ans == INT32_MAX / 10 && t_digit > 7)) {
                return 0; 
            }
            if (ans < INT32_MIN / 10 || (ans == INT32_MIN / 10 && t_digit < -8)) {
                return 0; 
            }
            
            ans = ans * 10 + t_digit; 
            x /= 10; 
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{


    return 0;
}
