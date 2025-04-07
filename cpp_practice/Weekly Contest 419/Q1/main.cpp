
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

// class Solution {
// public:
//     vector<int> findXSum(vector<int>& nums, int k, int x) {
//         map<int, int, std::greater<int>> fmap; 

//         for (int i = 0; i < k; i++) {
//             fmap[nums[i]]++; 
//         }

//         auto calcXSum = [&](map<int, int, std::greater<int>>& fmap, int x) {
//             int sum = 0; 
//             int cc = 0; 
//             for (auto it = fmap.begin(); it != fmap.end() && cc < x; ++it) {
//                 sum += (it->first) * (it->second); 
//                 cc++; 
//             }
//             return sum; 
//         }; 

//         vector<int> ans; 
//         ans.push_back(calcXSum(fmap, x)); 
//         for (int i = k; i < nums.size(); i++) {
//             int rem = nums[i-k]; 
//             fmap[rem]--; 
//             if (fmap[rem] == 0) {
//                 fmap.erase(rem); 
//             }

//             fmap[nums[i]]++; 
//             ans.push_back(calcXSum(fmap, x)); 
//         }

//         return ans; 
//     }
// };


class Solution {
public:
    // o(n) runtime complexity. 
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size(); 
        vector<int> ans; 
        unordered_map<int, int> fmap; 

        for (int i = 0; i < k; i++) {
            fmap[nums[i]]++; 
        }
        ans.push_back(calcXSum(fmap, x)); 

        for (int i = 1; i <= n-k; i++) {
            fmap[nums[i-1]]--; 
            if (fmap[nums[i-1]] == 0) {
                fmap.erase(nums[i-1]); 
            }

            fmap[nums[i+k-1]]++; 
            ans.push_back(calcXSum(fmap, x)); 
        }
        return ans;  
    }
private: 
    // o(k * logk) runtime. 
    int calcXSum(const unordered_map<int, int>& fmap, int x) {
        priority_queue<pair<int, int>> pq; // freq -- value. 

        for (const auto& ent : fmap) {
            pq.push(std::make_pair(ent.second, ent.first)); 
        }

        int sum = 0; 
        for (int i = 0; i < x && !pq.empty(); i++) {
            auto top = pq.top(); 
            pq.pop(); 
            sum += top.second * top.first; 
        }

        return sum; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {
        1, 1, 2, 2, 3, 4, 2, 3
    }; 
    Solution sol; 

    auto s1 = sol.findXSum(n1, 6, 2); 
    printArray(s1); 

    return 0;
}
