// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

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
#include <limits>
#include <sstream> 
#include <string> 

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

template <typename T>
void printArray(std::vector<T> values) {
    std::cout << "["; 
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i]; 
        if (values.size() - 1 > i) {
            std::cout << ", "; 
        }
    }
    std::cout << "]" << std::endl; 
}

template <typename T>
void printDoubleArray(std::vector<std::vector<T>> values) {
    cout << "[\n"; 
    for (int i = 0; i < values.size(); i++) {
        cout << "\t"; 
        printArray(values[i]); 
        if (i != values.size()-1) cout << ", "
    }
    cout << "]"
}

struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

// return index of target: 
int binSearch(vector<int> arr, int x) {

    int left = 0, right = arr.size()-1; 
    int mid; 

    while (left <= right) {
        mid = left + (right - left) / 2; 

        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] > x) {
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    if (right < 0) return 0; 
    if (left >= arr.size()) return arr.size() - 1; 

    if (abs(arr[left]-x) < abs(arr[right] - x)) {
        return left; 
    } else {
        return right; 
    }
}

/**
 * run a scan from right to left --> for previous lesser element. 
 * run a scan from left to right --> for next lesser element. 
 * 
 * then compute rectangle size --> you know width sizes, since you know the minimum height...
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(); 
        vector<int> l_idx(n, -1), r_idx(n, n);  
        stack<int> r1; 
        
        for (int i = 0; i < n; i++) {
            while (!r1.empty() && heights[i] < heights[r1.top()]) {
                r_idx[r1.top()] = i; 
                r1.pop(); 
            }
            r1.push(i); 
        }

        stack<int> r2; 
        for (int i = n - 1; i >= 0; i--) {
            while (!r2.empty() && heights[i] < heights[r2.top()]) {
                l_idx[r2.top()] = i; 
                r2.pop(); 
            }
            r2.push(i); 
        }

        int pot, max = 0; 
        for (int i = 0; i < n; i++) {
            pot = (r_idx[i] - l_idx[i] -1) * heights[i]; 
            max = pot > max ? pot : max; 
        }

        return max; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> r1 = {2,1,5,6,2,3}; 
    vector<int> r2 = {2,4}; 

    Solution s; 

    cout << s.largestRectangleArea(r1) << endl; 
    cout << s.largestRectangleArea(r2) << endl; 

    return 0;
}
