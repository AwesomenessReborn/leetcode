// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=problem-list-v2&envId=a9a7jmom

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
    int maxProfit(vector<int>& prices) {
        
        int p_max = 0; 
        int min = prices[0]; 
        if (prices.size() <= 1) return 0; 
        for (int i = 1; i < prices.size(); i++) {
            min = std::min(min, prices[i]); 

            p_max = std::max(p_max, prices[i] - min); 
        }

        return p_max; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {7,1,5,3,6,4}; 
    vector<int> n2 = {7,6,4,3,1}; 

    Solution sol; 
    cout << sol.maxProfit(n1) << endl; 
    cout << sol.maxProfit(n2) << endl; 



    return 0;
}
