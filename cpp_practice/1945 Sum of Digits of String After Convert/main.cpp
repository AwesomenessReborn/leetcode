// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=daily-question&envId=2024-09-03

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
    int getLucky(string s, int k) {
        string tmp = "";

        for (char c : s) {
            int value = (c - 'a' + 1); 
            tmp += to_string(value); 
        }

        int sum = 0;
        while (k--) {
            sum = 0;
            for (char c : tmp) {
                sum += (c - '0');  
            }
            tmp = to_string(sum);  
        }

        return sum;
    }
};


// class Solution {
// public:
//     int getLucky(string s, int k) {
//         string res = ""; 
//         int sum; 

//         for (int rep = 0; rep < k; rep++) {
//             string tmp = ""; 

//             for (char c : s) {
//                 int value = (c - 'a' + 1);  // from 1-26

//                 string sval = ""; 
//                 if (value >= 10) sval += (char)(value / 10);
//                 sval += (char)(value % 10); 
//                 tmp += sval; 
//             }
//             cout << "tmp value: " << tmp << endl; 

//             sum = 0; 
//             for (char c : tmp) {
//                 sum += (c - '0'); 
//             }

//         }

//         return sum; 
//     }
// };

int main(int argc, char const *argv[])
{
    string s1 = "iiii"; 
    string s2 = "leetcode"; 

    Solution sol; 

    cout << sol.getLucky(s1, 1) << endl; 
    cout << sol.getLucky(s2, 2) << endl; 

    return 0;
}
