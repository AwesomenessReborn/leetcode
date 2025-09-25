// template.cpp

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


string lcm(string a, string b) {
    int cc = 0; 

    while (cc < a.size() && cc < b.size() && a[cc] == b[cc]) cc++; 

    return a.substr(0, cc); 
}

int main() {

    string s1 = " awow2"; 
    string s2 = "wow3lfkja;lkfjak"; 

    cout << lcm(s1, s2) << endl; 

    cout << endl; 
}
