// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/?envType=daily-question&envId=2025-01-25

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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        const int n = nums.size(); 
        if (n <= 1) return nums; 

        vector<int> complete(n); 

        vector<int> sorted_nums = nums; 
        std::sort(sorted_nums.begin(), sorted_nums.end()); 
        
        vector<deque<int>> grouper; 
        unordered_map<int, int> mapper; 
        vector<int> mapper(n); // index:value -> group_id; 

        for (int i = 0; i < n; i++) {
            if (grouper.empty()) {
                grouper.emplace_back(1, sorted_nums[i]); 
                mapper[sorted_nums[i]] = 0;  // group 0. 
                continue;
            }

            if (sorted_nums[i] - grouper.back().back() > limit) {
                grouper.emplace_back(1, sorted_nums[i]);  // new group
                mapper[sorted_nums[i]] = grouper.size()-1; 
                continue;
            }

            grouper.back().push_back(sorted_nums[i]); 
            mapper[sorted_nums[i]] = grouper.size()-1; // indicate which group

        }

        for (int i = 0; i < n; i++) {
            // target -- nums[i], use map to find group, pop and push from that group. 

            int group_id = mapper[nums[i]]; 

            complete.push_back(grouper[group_id].front()); 
            grouper[group_id].pop_front(); 
        }

        return complete; 
    }
};

int main() {

    Solution s; 

    vector<int> n1 = {1,5,3,9,8}; 
    vector<int> n2 = {1,7,6,18,2,1}; 

    const int lim1 = 2, lim2 = 3; 

    printArray(s.lexicographicallySmallestArray(n1, lim1)); 

    printArray(s.lexicographicallySmallestArray(n2, lim2)); 
    
    return 0;   
}