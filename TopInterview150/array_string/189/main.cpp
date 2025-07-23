
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
    void rotate(vector<int>& nums, int k) {
        const int n = nums.size(); 
        k = k % n; 
        if (k == 0) return; 

        vector<int> buff(nums.end() - k, nums.end()); 

        // for (int i = n-1; i >= k; i--) {
        //     nums[i] = nums[i-k]; 
        // }

        // for (int i = 0; i < k; i++) {
        //     nums[i] = buff[i]; 
        // }

        reverse(nums.begin(), nums.end()); 
        reverse(nums.begin(), nums.begin()+k); 
        reverse(nums.begin()+k, nums.end()); 
    }
};

int main()
{
    Solution s; 

    vector<int> n1 = {1,2,3,4,5,6,7}; 
    vector<int> n2 = {-1,-100,3,99}; 

    cout << "\n array before: ---- " << endl; 

    printArray(n1); 
    printArray(n2); 

    cout << "\n array after: ---- " << endl; 

    s.rotate(n1, 3); s.rotate(n2, 2); 

    printArray(n1); 
    printArray(n2); 

}; 
