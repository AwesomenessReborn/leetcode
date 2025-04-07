// https://leetcode.com/problems/combination-sum-ii/description/

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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        const int n = candidates.size(); 
        vector<vector<int>> ans; 

        vector<int> current; 

        sort(candidates.begin(), candidates.end()); 

        backtrack(ans, current, candidates, target, 0, n); 

        return ans; 
    }
private: 
    void backtrack(vector<vector<int>> &ans, vector<int> &cursol,
                      vector<int> &candidates, int target, int idx, int n) {
        if (target == 0) {
            ans.push_back(cursol); 
            return; 
        }

        for (int i = idx; i < n && target >= candidates[i]; ++i) {
            if (i == idx || candidates[i] != candidates[i-1]) {
                cursol.push_back(candidates[i]); 
                backtrack(ans, cursol, candidates,
                             target - candidates[i], i + 1, n); 
                cursol.pop_back(); 
            }
        }

    }
};

int main() {
    vector<int> n1 = {10,1,2,7,6,1,5};
    vector<int> n2 = {2,5,2,1,2}; 

    Solution s; 

    cout << "1" << endl; 
    printDoubleArray(s.combinationSum2(n1, 8)); 
    cout << endl; 
    cout << endl; 

    cout << "2" << endl; 
    printDoubleArray(s.combinationSum2(n2, 5)); 
    cout << endl; 
    cout << endl; 

    return 0;   
}
