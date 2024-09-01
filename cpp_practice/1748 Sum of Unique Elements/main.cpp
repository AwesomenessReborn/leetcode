// https://leetcode.com/problems/sum-of-unique-elements/description/?envType=problem-list-v2&envId=eeyho3um

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
    int sumOfUnique(vector<int>& nums) {
        int sum = 0; 
        unordered_map<int, int> fq; 
        for (int value : nums) {
            fq[value]++; 
        }
        for (auto it = fq.begin(); it != fq.end(); ++it) {
            if (it->second == 1) sum += it->first; 
        }
        return sum; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {1,2,3,2}; 
    vector<int> n2 = {1,1,1,1,1}; 
    vector<int> n3 = {1,2,3,4,5}; 
    Solution sol; 
    cout << sol.sumOfUnique(n1) << endl; 
    cout << sol.sumOfUnique(n2) << endl; 
    cout << sol.sumOfUnique(n3) << endl; 

    return 0;
}
