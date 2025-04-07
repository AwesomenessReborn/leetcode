// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/?envType=daily-question&envId=2025-03-02

#include <numeric>
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
        if (i != values.size()-1) cout << ", "; 
    }
    cout << "]"; 
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


class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {       
        const int n1size = nums1.size(), n2size = nums2.size(); 
        vector<vector<int>> res; 
        res.reserve(n1size + n2size);

        int i1 = 0, i2 = 0; 

        while (i1 < n1size || i2 < n2size) {

            if (i1 >= n1size) {
                res.push_back({nums2[i2][0], nums2[i2][1]});  
                i2++; 
                continue;
            }
            if (i2 >= n2size) {
                res.push_back({nums1[i1][0], nums1[i1][1]});  
                i1++; 
                continue;
            }

            int id1 = nums1[i1][0], id2 = nums2[i2][0]; 
            if (id1 == id2) {
                res.push_back({id1, nums1[i1][1]+nums2[i2][1]}); 
                i1++; i2++; 
                continue;
            }
            if (id1 > id2) {
                res.push_back({id2, nums2[i2][1]});  
                i2++; 
            } else {
                res.push_back({id1, nums1[i1][1]});  
                i1++; 
            }
        }

        return res; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
