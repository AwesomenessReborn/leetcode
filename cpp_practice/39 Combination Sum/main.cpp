// https://leetcode.com/problems/combination-sum/

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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        const int n = candidates.size(); 

        vector<vector<int>> ans; 
        vector<int> curr;

        backtrack(ans, target, n, 0, candidates, curr, 0); 

        return ans; 
    }
private: 
    void backtrack(vector<vector<int>>& ans, int target, int n, int curSum, vector<int>& candidates, vector<int>& curr, int idx) {
        if (curSum > target) return; 

        if (curSum == target) {
            ans.push_back(curr); 
            return; 
        }

        for (int i = idx; i < n; i++) {
            curSum += candidates[i]; 
            curr.push_back(candidates[i]); 
            backtrack(ans, target, n, curSum, candidates, curr, i); 
            curr.pop_back(); 
            curSum -= candidates[i]; 
        }
    }
};

int main() {
    vector<int> n1 = {2,3,6,7}; 
    vector<int> n2 = {2,3,5}; 
    vector<int> n3 = {2}; 

    Solution s; 

    cout << "1: " << endl; 
    printDoubleArray(s.combinationSum(n1, 7)); 
    cout << endl; 
    cout << endl; 

    cout << "2: " << endl; 
    printDoubleArray(s.combinationSum(n2, 8)); 
    cout << endl; 
    cout << endl; 

    cout << "3: " << endl; 
    printDoubleArray(s.combinationSum(n3, 1)); 
    cout << endl; 
    cout << endl; 
    
    return 0;   
}; 
