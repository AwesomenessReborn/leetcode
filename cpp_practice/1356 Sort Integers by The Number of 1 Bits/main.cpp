// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

#include <map>
#include <array>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

template <typename T>
void printArray(std::vector<T> values)
{
    std::cout << "[";
    for (int i = 0; i < values.size(); i++)
    {
        std::cout << values[i];
        if (values.size() - 1 > i)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

    // auto printer = [&](int value) {
    //     cout << "some randome val=" << n << endl; 
    // }; 
    // for (int i = 0; i < 5; i++) {
    //     printer(i); 
    // }

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto getbits = [](int value) {
            int cnt = 0; 
            for (int i = 0; i < 14; i++) {
                if (value & (1 << i)) cnt++; 
            }
            return cnt; 
        }; 

        std::array<std::multiset<int>, 14> bitcounter; 
        for (int i = 0; i < arr.size(); i++) {
            bitcounter[getbits(arr[i])].insert(arr[i]); 
        }
        vector<int> ans; 
        for (int i = 0; i < 14; i++) {
            for (auto it = bitcounter[i].begin(); it != bitcounter[i].end(); ++it) {
                ans.push_back(*it); 
            }
        }
        return ans; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
