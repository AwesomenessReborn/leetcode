// https://leetcode.com/problems/longest-happy-string/?envType=daily-question&envId=2024-10-16

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

/**
 * make sure you get as close to the length of a+b+c.
 *
 *
 *          always make sure to use the most frequent character every time.
 *
 *          maintain que to track what's the first, second, and third highest letter.
 */

struct CompFrequency
{
    bool operator()(const std::pair<int, char> &a, const std::pair<int, char> &b)
    {
        return a.first > b.first;
    }
};

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string result = "";

        while (!pq.empty())
        {
            auto [count1, char1] = pq.top();
            pq.pop();

            if (result.size() >= 2 && result.back() == char1 && result[result.size() - 2] == char1)
            {
                if (pq.empty())
                    break;

                auto [count2, char2] = pq.top();
                pq.pop();

                result += char2;
                count2--;

                if (count2 > 0)
                    pq.push({count2, char2});

                pq.push({count1, char1});
            }
            else
            {
                result += char1;
                count1--;

                if (count1 > 0)
                    pq.push({count1, char1});
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    cout << sol.longestDiverseString(1, 1, 7) << endl;
    cout << sol.longestDiverseString(7, 1, 0) << endl;

    return 0;
}
