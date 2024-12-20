
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

int main() {

    // string s = "09"; 
    // cout << ((int)s[0])-48 << endl; 
    // cout << ((int)s[1])-48 << endl; 
    // cout << (int)'a' << endl; 
    // cout << (int)'z' << endl; 
    // cout << (int)'A' << endl; 
    // cout << (int)'Z' << endl; 

    // string sss = "djflaj"; 
    // cout << (int)sss[0] << endl; 
    // cout << (int)sss[2] << endl; 

    std::string s; 

    s.reserve(2); 

    s.push_back('a'); 

    s.push_back('a'); 
    s.push_back('a'); 
    s.push_back('a'); 

    cout << s << endl ; 

    // queue<int> qq; 

    // qq.push(1); 

    // qq.push(1); 
    // qq.push(1); 
    // qq.push(1); 

    return 0;   
}
