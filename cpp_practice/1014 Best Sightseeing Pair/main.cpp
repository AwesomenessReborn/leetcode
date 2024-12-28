// https://leetcode.com/problems/best-sightseeing-pair/?envType=daily-question&envId=2024-12-27

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
#include <climits>

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
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(); 
        vector<int> i_s(n); 
        vector<int> j_s(n); 
        int max = INT_MIN;

        for (int i = 0; i < n; i++) {
            i_s[i] = values[i] + i; 
            j_s[i] = (values[i] - i); 
            i_s[i] = (i-1>=0) ? std::max(i_s[i], i_s[i-1]) : i_s[i]; 
        }
        for (int i = 0; i< n-1; i++) {max = std::max(max, i_s[i] + j_s[i+1]); }

        return max; 
    }
};

// class Solution {
// public:
//     int maxScoreSightseeingPair(vector<int>& values) {
//         int max_i = values[0]; 
//         int max_score = INT_MIN; 

//         for (int j = 1; j < values.size(); j++) {
//             max_score = std::max(max_score, max_i + values[j] - j);
//             max_i = std::max(max_i, values[j] + j);
//         }

//         return max_score;
//     }
// };

int main(int argc, char const *argv[])
{

    Solution s; 
    vector<int> n1 = {8,1,5,2,6}; 
    vector<int> n2 = {1,2}; 

    cout << s.maxScoreSightseeingPair(n1) <<endl; 
    cout << s.maxScoreSightseeingPair(n2) <<endl; 

    return 0;


}
