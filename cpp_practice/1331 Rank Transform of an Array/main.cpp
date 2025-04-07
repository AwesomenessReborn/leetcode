// https://leetcode.com/problems/rank-transform-of-an-array/

#include <map>
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

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr; 
        sort(sorted.begin(), sorted.end()); 

        unordered_map<int, int> ranker; 
        int rank = 1; 
        for (int value : sorted) {
            if (ranker.find(value) == ranker.end()) {
                ranker[value] = rank++; 
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = ranker[arr[i]]; 
        }

        return arr; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {40,10,20,30}; 
    vector<int> n2 = {100,100,100}; 
    vector<int> n3 = {37,12,28,9,100,56,80,5,12}; 
    Solution sol; 

    printArray(sol.arrayRankTransform(n1)); 
    printArray(sol.arrayRankTransform(n2)); 
    printArray(sol.arrayRankTransform(n3)); 

    return 0;
}
