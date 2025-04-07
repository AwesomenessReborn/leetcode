// https://leetcode.com/problems/generate-parentheses/description/

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
    vector<string> generateParenthesis(int n) {
        vector<string> ans; 

        std::string cur; 
        cur.reserve(n*2); 

        helper(ans, cur, 0, 0, n); 

        return ans; 
    }
private: 
    void helper(vector<string>& ans, string& str, int open, int close, int n) {

        if (str.size() == (n*2)) {
            ans.push_back(str); 
            return; 
        }

        if (open < n) {
            str.push_back('('); 
            helper(ans, str, open+1, close, n); 
            str.pop_back(); 
        }

        if (close < open) {
            str.push_back(')'); 
            helper(ans, str, open, close + 1, n); 
            str.pop_back(); 
        }

    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
