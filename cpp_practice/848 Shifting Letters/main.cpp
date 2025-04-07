// https://leetcode.com/problems/shifting-letters/description/

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
    string shiftingLetters(string s, vector<int>& shifts) {
        const int n = s.size(); 

        int ss = 0; 

        for (int i = n-1; i >= 0; i--) {
            ss += shifts[i]; 
            ss %= 26; 

            int c = s[i]; 
            c += (ss); 
            while (c > 'z') c-=26; 

            s[i] = (char)c; 
        }

        return s; 
    }
};

int main() {
    string s1 = "abc"; 
    string s2 = "aaa"; 
    string s3 = "ruu"; 

    vector<int> n1 = {3,5,9}; 
    vector<int> n2 = {1,2,3}; 
    vector<int> n3 = {26,9,17}; 

    Solution s; 

    cout << s.shiftingLetters(s1, n1) << endl; 
    cout << "expected: rpl\n" << endl; 

    cout << s.shiftingLetters(s2, n2) << endl; 
    cout << "expected: gfd\n" << endl; 

    cout << s.shiftingLetters(s3, n3) << endl; 
    cout << "expected: ??\n" << endl; 

    return 0;   
}
