// https://leetcode.com/problems/permutations/description/

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
    vector<vector<int>> permute(vector<int>& nums) {
        const int n = nums.size(); 
        
        vector<vector<int>> ans; 

        vector<bool> used(n, false); 

        vector<int> curr; 
        backtrack(ans, used, n, curr, nums); 

        return ans; 
    }
private: 
    void backtrack(vector<vector<int>>& ans, vector<bool>& used, int n, vector<int>& curr, vector<int>& nums) {
        if (curr.size() == n) {
            ans.push_back(curr); 
            return; 
        }
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = true; 
                curr.push_back(nums[i]); 
                backtrack(ans, used, n, curr, nums); 
                used[i] = false; 
                curr.pop_back(); 
            }
        }
    }
};

int main() {
    vector<int> n1 = {1,2,3}; 
    vector<int> n2 = {0,1}; 
    vector<int> n3 = {1}; 

    vector<int> n4 = {1,2,3,4,12,123,33, 11, 333}; 

    Solution s; 

    printDoubleArray(s.permute(n4)); 
    cout << endl; 

    // printDoubleArray(s.permute(n2)); 
    // cout << endl; 

    // printDoubleArray(s.permute(n3)); 
    // cout << endl; 
    
    return 0;   
}
