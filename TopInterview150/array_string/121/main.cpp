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
#include <climits>
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

template <typename T>
void printDoubleArray(std::vector<std::vector<T>> values)
{
    cout << "[\n";
    for (int i = 0; i < values.size(); i++)
    {
        cout << "\t";
        printArray(values[i]);
        if (i != values.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

struct CompareDistance
{
    bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b)
    {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

// return index of target:
int binSearch(vector<int> arr, int x)
{

    int left = 0, right = arr.size() - 1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (right < 0)
        return 0;
    if (left >= arr.size())
        return arr.size() - 1;

    if (abs(arr[left] - x) < abs(arr[right] - x))
    {
        return left;
    }
    else
    {
        return right;
    }
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size(); 
        if (n == 1) return 0; 

        int mincost = prices[0], maxprof = 0; 

        for (int i = 0; i < n; i++) {
            mincost = std::min(mincost, prices[i]); 
            maxprof = std::max(prices[i] - mincost, maxprof); 
        }

        return maxprof; 
    }
};

int main()
{
    Solution s;

    vector<int> n1 = {7,1,5,3,6,4};
    vector<int> n2 = {7,6,4,3,1};

    cout << "res 1: " << s.maxProfit(n1) << endl;
    cout << "actually: 5" << endl; 
    cout << "res 2: " << s.maxProfit(n2) << endl;
    cout << "actually: 0" << endl; 

};


