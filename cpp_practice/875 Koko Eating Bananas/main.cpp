// https://leetcode.com/problems/koko-eating-bananas/

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
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = *max_element(piles.begin(), piles.end()); 
        int left = 1; 

        while (left <= right) {
            int mid = left + (right - left) / 2; 

            long long chours = 0; 
            for (int value : piles) {
                chours += (value + mid - 1) / mid; 
            }
            if (chours > h) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        return left;
    }
};

int main(int argc, char const *argv[])
{



    return 0;
}
