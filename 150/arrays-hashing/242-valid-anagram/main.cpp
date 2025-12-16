// 242 valid anagram

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
#include <bitset>

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
    for (auto &item : values) {
        std::cout << item; 
        if (item != values.back()) cout << ", "; 
    }
    std::cout << "]"; 
}

template <typename T>
void printDoubleArray(std::vector<std::vector<T>> values, bool onNewLine) {
    if (onNewLine) {
        cout << "[\n"; 
        for (auto &item : values) {
            cout << "\t"; 
            printArray(item); 
            if (item != values.back()) cout << ", ";
            cout << endl;
        }
        cout << "]"; 
        return; 
    }

    cout << "["; 

    for (auto &item: values) {
        printArray(item); 
        if (item != values.back()) cout << ", "; 
    }

    cout << "]\n"; 

}

struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

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

bool check(char pot) {
    return pot == 'a' || pot == 'e' || pot == 'i' || pot == 'o' || pot == 'u'; 
}


vector<vector<int>> solution(vector<vector<int>> a) {
    const int n = a.size(); 
    
    unordered_map<int, vector<int>> coll; 

    for (int group = 0; group < n; group++) {
        float mean = std::accumulate(a[group].begin(), a[group].end(), 0) / a[group].size(); 

        coll[mean].push_back(group); 
    }

    vector<vector<int>> res; 
    for (auto pp : coll) {
        vector<int> cur; 

        for (auto value : pp.second) {
            cur.push_back(value); 
        }

        res.push_back(cur); 
    }

    return res; 
}

void printBits(unsigned int value) {
    std::bitset<32> bits(value);
    std::cout << bits << "\n";
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        const int n = s.size();
        if (n != t.size()) return false;
        int buf[26] = { 0 };

        for (int i = 0; i < n; i++) {
            buf[s[i] - 'a']++;
            buf[t[i] - 'a']--;
        }

        for (int val: buf) if (val != 0) return false;

        return true;
    }
};

int main() {
    string s1 = "anagram";
    string t1 = "nagaram";
    string s2 = "rat";
    string t2 = "car";

    Solution s; 

    cout << s.isAnagram(s1, t1) << endl; 
    cout << s.isAnagram(s2, t2) << endl; 

    return 0;
}
