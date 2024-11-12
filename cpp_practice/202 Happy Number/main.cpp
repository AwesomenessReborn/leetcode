// https://leetcode.com/problems/happy-number/description/

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
private: 
    int eval(int val) {
        int r = 0; 
        while (val > 0) {
            r += ((val % 10) * (val % 10)); 
            val /= 10; 
        }
        return r; 
    }
public:
    bool isHappy(int n) {
        unordered_set<int> rec; 

        while (n != 1) {
            // cout << "loop value --n--: " << n << endl; 
            if (rec.count(n) > 0) return false; 
            rec.insert(n); 

            n = eval(n); 
        }

        return true; 
    }
};


int main(int argc, char const *argv[])
{
    int n1 = 19; // true
    int n2 = 2; // false 
    int n3 = 7; // true
    Solution s; 

    cout << s.isHappy(n3) << endl; ; 

    return 0;
}
