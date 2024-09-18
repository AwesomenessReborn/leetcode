// https://leetcode.com/problems/find-k-closest-elements/?envType=problem-list-v2&envId=eofbf01i

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

// binary search to target: x
// res size must be k; 
// then populate res by checking whichever is closer, to the left or right of arr. 
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() == k) return arr; 

        auto approxBinSearch = [](vector<int>& arr, int x) {
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
            if (left >= arr.size()) return (int)arr.size() - 1; 

            if (abs(arr[left]-x) < abs(arr[right] - x)) {
                return left; 
            } else {
                return right; 
            }
        }; 

        int mid = approxBinSearch(arr, x); 
        int left = (mid-1 >= 0) ? mid-1 : 0; 
        int right = (mid+1 < arr.size()) ? mid+1 : arr.size()-1; 

        left = mid; 
        right = mid; 

        while (right - left + 1 < k) {
            if (left == 0) {
                right++; 
            } else if (right == arr.size() - 1) {
                left--; 
            } else if (abs(arr[left - 1] - x) <= abs(arr[right + 1] - x)) {
                left--; 
            } else {
                right++; 
            }
        }

        return std::vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a1 = {1, 3}; 
    vector<int> a2 = {1,2,3,4,5}; 
    vector<int> a3 = {1,10,15,25,35,45,50,59}; 
    
    int k1 = 1; 
    int k2 = 4; 
    int k3 = 1; 

    int x1 = 2; 
    int x2 = 3; 
    int x3 = 30; 

    Solution sol; 
    // auto r1 = sol.findClosestElements(a1, k1, x1);
    // auto r2 = sol.findClosestElements(a2, k2, x2); 
    auto r3 = sol.findClosestElements(a3, k3, x3); 

    // printArray(r1); // should output 1. 
    // printArray(r2); 
    printArray(r3);  // should output 25. 

    return 0;
}
