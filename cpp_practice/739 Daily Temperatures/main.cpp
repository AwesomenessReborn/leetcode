// https://leetcode.com/problems/daily-temperatures/description/

#include <stack> 
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


struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

// return index of target: 
int binSearch(vector<int> arr, int x) {

    int left = 0, right = arr.size()-1; 
    int mid; 

    while (left <= right) {
        mid = left + (right - left) / 2; 

        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] > x) {
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    if (right < 0) return 0; 
    if (left >= arr.size()) return arr.size() - 1; 

    if (abs(arr[left]-x) < abs(arr[right] - x)) {
        return left; 
    } else {
        return right; 
    }
}

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& temperatures) {
//         stack<int> s; 

//         vector<int> ans; 
//         ans.reserve(temperatures.size()); 

//         s.push(0); 

//         for (int i = 0; i < temperatures.size(); i++) {
//             if (s.empty()) {
//                 s.push(i); 
//                 continue;
//             }

//             while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
//                 ans[s.top()] = temperatures[i]; 
//                 s.pop(); 
//             }

//             s.push(i); 
//         }

//         while (!s.empty()) {
//             ans[s.top()] = 0; 
//         }

//         return ans; 
//     }
// };

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size(); 
        stack<int> dec; 
        vector<int> ans(n, 0); 

        for (int tmp_idx = 0; tmp_idx < n; tmp_idx++) {
            while (!dec.empty() && temperatures[dec.top()] < temperatures[tmp_idx]) {
                ans[dec.top()] = tmp_idx - dec.top(); 
                dec.pop(); 
            }
            dec.push(tmp_idx); 
        }
        
        return ans; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
