// main.cpp
// problem 1

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

void printBits(unsigned int value) {
    std::bitset<32> bits(value);
    std::cout << bits << "\n";
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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> rec;  // value -> location
        const int n = nums.size(); 

        for (int i = 0; i < n; i++) {
            auto it = rec.find(target - nums[i]); 
            if (it != rec.end()) {
                return {it->second, i}; 
            }

            rec[nums[i]] = i; 
        }

        return {}; 
    }
};

int main() {
    Solution s; 

    cout << "1" << endl; 
    vector<int> a{2, 7, 11, 15};
    printArray(s.twoSum(a, 9));
    cout << endl; 

    cout << "2" << endl; 
    vector<int> b{3,2,4};
    printArray(s.twoSum(b, 6));
    cout << endl; 

    cout << "3" << endl; 
    vector<int> c{3,3};
    printArray(s.twoSum(c, 6));
    cout << endl; 

}
