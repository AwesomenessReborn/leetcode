// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-07

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
    vector<int> minOperations(string boxes) {
        const int n = boxes.size(); 
        vector<int> ans(n, 0); 

        int cc = 0, mov = 0; 
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (boxes[i] == '1') cc++; 
                continue;
            }

            mov += cc; 
            ans[i] += mov; 

            if (boxes[i] == '1') cc++; 
        }

        cc = 0, mov = 0; 
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                if (boxes[i] == '1') cc++; 
                continue;
            }

            mov += cc; 
            ans[i] += mov; 

            if (boxes[i] == '1') cc++; 
        }

        return ans; 
    }
};

int main() {
    string s1 = "110"; 
    string s2 = "001011"; 

    Solution s; 

    cout << "1. " << endl; 
    printArray(s.minOperations(s1)); 
    cout << "2. " << endl; 
    printArray(s.minOperations(s2)); 
    
    return 0;   
}
