

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
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]; 
        if (nums.size() == 2) return std::max(nums[0], nums[1]); 

        int pot, pp = nums[0], p = std::max(nums[0], nums[1]); 

        // cout << "pot: " << pot << endl; cout << "p: " << p << endl; 
        // cout << "pp: " << pp << endl; 

        // cout << endl; 

        for (int i = 2; i < nums.size(); i++) {
            pot = std::max(p, pp + nums[i]); 

            pp = p; 
            p = pot; 

            // cout << "pot: " << pot << endl; 
            // cout << "p: " << p << endl; 
            // cout << "pp: " << pp << endl; 
            // cout << endl; 
        }

        return std::max(pp, p); 
    }
};

int main() {
    vector<int> n1 = {1,2,3,1}; 
    vector<int> n2 = {2,7,9,3,1}; 
    vector<int> n3 = {2,1,1,2}; 
    
    Solution s; 

    // cout << s.rob(n1) << endl; 
    // cout << "expected: 4 \n" << endl; 

    // cout << s.rob(n2) << endl; 
    // cout << "expected: 12 \n" << endl; 

    cout << s.rob(n3) << endl; 
    cout << "expected: 4 \n" << endl; 

    return 0;   
}