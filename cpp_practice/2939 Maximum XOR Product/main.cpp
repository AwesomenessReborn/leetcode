// https://leetcode.com/problems/maximum-xor-product/

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


/**
 * n --> should be the total count of bits. 
 *      maximize a XOR x. 
 *      maximize b XOR x. 
 * 
 *      XOR --> 1 ^ 0 = 1
 *              1 ^ 1 = 0
 *              0 ^ 0 = 0
 *              0 ^ 1 = 1
 * 
 *      for (each of n bits): 
 *              
 */
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        long long val, bita, bitb, MOD = 1e9 + 7; 

        for (int i = n - 1; i >= 0; i--) {
            val = 1LL << i;
            bita = a & val;
            bitb = b & val;
            if (bita && bitb) {
                continue;
            } else if (bita) {
                if (a > b) {
                    a ^= val;
                    b |= val;
                }
            } else if (bitb) {
                if (b > a) {
                    a |= val;
                    b ^= val;
                }
            } else {
                a |= val;
                b |= val;
            }
        }
        // Calculate XOR and take modulus
        // a = a % MOD;
        // b = b % MOD;
        // return (a * 1LL * b) % MOD;
        return ((a%MOD) * 1LL *(b%MOD)) % MOD;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 

    cout << sol.maximumXorProduct(12, 5, 4) << endl; 
    cout << sol.maximumXorProduct(6, 7, 5) << endl; 
    cout << sol.maximumXorProduct(1, 6, 3) << endl; 

    return 0;
}
