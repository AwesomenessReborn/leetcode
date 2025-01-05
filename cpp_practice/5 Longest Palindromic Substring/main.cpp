// https://leetcode.com/problems/longest-palindromic-substring/editorial/?envType=problem-list-v2&envId=dynamic-programming

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
    string longestPalindrome(string s) {
        if (s.size() == 1) return s; 

        // begin index is inclusive, end index is exclusive
        std::array<int, 2> odd = {-1, -1}, even = {-1, -1}; // keep track of longest. 
        const int n = s.size(); 

        std::array<int, 2> buffer; 

        // even case: 
        for (int i = 0; i < n-1; i++) {
            
            buffer = {i+1, i};      // begin with indexes in wrong order. 
            while ((buffer[0]-1) >= 0 && (buffer[1]+1) < n &&
                s[buffer[0]-1] == s[buffer[1]+1]) {
                buffer[0]--; 
                buffer[1]++; 
            }
            
            if (buffer[1] - buffer[0] > even[1] - even[0]) {
                even = buffer; 
            }
        }

        // odd case: 
        for (int i = 0; i < n; i++) {

            buffer = {i, i};        // begin at same index. 
            while ((buffer[0]-1) >= 0 && (buffer[1]+1) < n 
                && s[buffer[0]-1] == s[buffer[1]+1]) {
                buffer[0]--; 
                buffer[1]++; 
            }
             
            if (buffer[1] - buffer[0] > odd[1] - odd[0]) {
                odd = buffer; 
            }

        }

        if (odd[1] - odd[0] > even[1] - even[0]) {
            return s.substr(odd[0], odd[1]-odd[0]+1); 
        }
        return s.substr(even[0], even[1]-even[0]+1); 
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "babad"; 
    string s2 = "cbbd"; 
    string s3 = "a"; 

    Solution s; 

    cout << "result: \t" << s.longestPalindrome(s1) << endl; 
    cout << "expected: \t" << "bab" << endl; 
    cout << endl; 

    cout << "result: \t" << s.longestPalindrome(s2) << endl; 
    cout << "expected: \t" << "bb" << endl; 
    cout << endl; 

    cout << "result: \t" << s.longestPalindrome(s3) << endl; 
    cout << "expected: \t" << "a" << endl; 
    cout << endl; 

    return 0;
}
