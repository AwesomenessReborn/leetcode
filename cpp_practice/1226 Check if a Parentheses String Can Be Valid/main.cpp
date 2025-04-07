

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

class Solution
{
public:
    bool canBeValid(string s, string locked)
    {
        const int n = s.size();
        if (n % 2 == 1)
            return false;

        vector<int> openB, unlocked;
        openB.reserve(n);
        unlocked.reserve(n);

        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0')
            {
                unlocked.push_back(i);
            }
            else if (s[i] == '(')
            {
                openB.push_back(i);
            }
            else if (s[i] == ')')
            {
                if (openB.size() > 0)
                {
                    openB.pop_back();
                }
                else if (unlocked.size() > 0)
                {
                    unlocked.pop_back();
                }
                else
                {
                    return false;
                }
            }
        }

        while (openB.size() > 0 && unlocked.size() > 0 && openB.back() < unlocked.back())
        {
            openB.pop_back();
            unlocked.pop_back();
        }

        if (openB.size() > 0)
            return false;

        return true;
    }
};

int main()
{
    string s1 = "))()))";
    string s2 = "()()";
    string s3 = ")";

    string l1 = "010100";
    string l2 = "0000";
    string l3 = "0";

    Solution s;

    cout << s.canBeValid(s1, l1) << endl;
    cout << s.canBeValid(s2, l2) << endl;
    cout << s.canBeValid(s3, l3) << endl;

    return 0;
}
