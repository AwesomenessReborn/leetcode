// https://leetcode.com/problems/sqrtx/?envType=problem-list-v2&envId=a9a7jmom

#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

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
    int mySqrt(int x) {
        int left = 0; 
        int right = x;         
        
        while (left < right) {
            int mid = (left + right + 1) >> 1; 

            if (mid <= x/mid) {
                left = mid; 
            } else {
                right = mid-1; 
            }
        }
        return left; 
    }
};

int main(int argc, char const *argv[])
{



    return 0;
}
