// https://leetcode.com/problems/find-center-of-star-graph/

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

// just take first edge and second edge, find the common value.
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
            return edges[0][0];
        if (edges[0][1] == edges[1][0] || edges[0][1] == edges[1][1])
            return edges[0][1];
        return -1;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
