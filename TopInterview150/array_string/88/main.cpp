
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> n1buff(nums1.begin(), nums1.begin() + m); 

        int x=0, y=0, t=0; 

        while (x < m && y < n) {
            if (n1buff[x] < nums2[y]) {
                nums1[t++] = n1buff[x++]; 
            } else {
                nums1[t++] = nums2[y++]; 
            }
        }

        while (x < m) nums1[t++] = n1buff[x++];
        while (y < n) nums1[t++] = nums2[y++];
    }
};

int main()
{
    vector<int> n1 = {1,2,3,0,0,0}; 
    vector<int> n2 = {2,5,6}; 


    Solution s; 

    printArray(n1); 
    printArray(n2); 

    s.merge(n1, 3, n2, 3); 

    printArray(n1); 
    printArray(n2); 
    
}

