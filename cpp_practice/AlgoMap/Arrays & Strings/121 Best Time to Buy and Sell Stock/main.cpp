// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <map>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>

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


        return 0; 
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
