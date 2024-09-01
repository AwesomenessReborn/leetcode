// https://leetcode.com/problems/two-out-of-three/description/?envType=problem-list-v2&envId=eeyho3um

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
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int, array<int, 3>> mp; // value : presense; 
        for (int value : nums1) {
            mp[value][0] = 1; 
        }
        for (int value : nums2) {
            mp[value][1] = 1; 
        }
        for (int value : nums3) {
            mp[value][2] = 1; 
        }
        vector<int> res; 
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int rep = it->second[0] + it->second[1] + it->second[2]; 
            if (rep > 1) res.push_back(it->first); 
        }
        return res; 
    }
};

int main(int argc, char const *argv[])
{



    return 0;
}
