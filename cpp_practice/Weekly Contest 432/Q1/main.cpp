

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
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        const int gridRowCnt = grid.size(), gridColCnt = grid[0].size(); 
        int cc = 0; 
        int diff = 1; 
        vector<int> res; 

        bool acc = true; 
        for (int row = 0; row < gridRowCnt; row++) {
            
            if (diff == 1) {
                for (int i = 0; i < gridColCnt; i++) {
                    if (acc) {
                        res.push_back(grid[row][i]); 
                        acc = false; 
                    } else {
                        acc = true; 
                    }
                }
            } else {
                for (int i = gridColCnt-1; i >= 0; i--) {
                    if (acc) {
                        res.push_back(grid[row][i]); 
                        acc = false; 
                    } else {
                        acc = true; 
                    }
                }
            }

            diff *= -1; 
        }

        return res; 
    }
}; 

int main() {

    vector<vector<int>> g1 = {
        {1,2}, 
        {3,4}
    }; 

    vector<vector<int>> g2 = {
        {2,1}, 
        {2,1}, 
        {2,1}
    }; 

    Solution s; 

    printArray(s.zigzagTraversal(g1)); 
    printArray(s.zigzagTraversal(g2)); 
    
    
    return 0;   
}
