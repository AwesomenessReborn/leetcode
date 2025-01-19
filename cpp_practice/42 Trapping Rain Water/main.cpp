

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
    int trap(vector<int>& height) {
        const int n = height.size(); 

        vector<int> leftM(n); 
        vector<int> rightM(n); 

        int running_max = 0; 
        for (int i = 1; i < n; i++) {
            if (height[i-1] > running_max) running_max = height[i-1]; 

            leftM[i] = running_max; 
        }

        running_max = 0; 
        for (int i = n-2; i >= 0; i--) {
            if (height[i+1] > running_max) running_max = height[i+1]; 

            rightM[i] = running_max;
        }

        int cc = 0, w = 0; 
        for (int i = 0; i < n; i++) {
            w = std::min(leftM[i], rightM[i]) - height[i];
            if (w > 0) cc += w; 
        }

        return cc; 
    }
};

int main() {

    vector<int> n1 = {0,1,0,2,1,0,1,3,2,1,2,1}; 
    vector<int> n2 = {4,2,0,3,2,5}; 

    Solution s; 


    cout << "question: " << endl; 
    printArray(n1); 

    cout << "ans: " << endl; 
    s.trap(n1); 
    
    return 0;   
}


