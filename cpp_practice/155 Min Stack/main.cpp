

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
#include <stack>

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



// class MinStack {
// private: 
//     vector<pair<int, int>> stk; // value -> running min

// public:
//     MinStack() {
//     }
    
//     void push(int val) {
//         if (stk.empty()) {
//             stk.push_back({val, val});
//         } else {
//             int currentMin = stk.back().second;
//             stk.push_back({val, std::min(currentMin, val)});
//         }
//     }
    
//     void pop() {
//         if (!stk.empty()) stk.pop_back(); 
//     }
    
//     int top() {
//         return stk.back().first; 
//     }
    
//     int getMin() {
//         return stk.back().second; 
//     }
// };

class MinStack {
private: 
    stack<pair<int, int>> stk; 

public:
    MinStack() {
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push({val, val});
        } else {
            int currentMin = stk.top().second;
            stk.push({val, std::min(currentMin, val)});
        }
    }
    
    void pop() {
        if (!stk.empty()) stk.pop(); 
    }
    
    int top() {
        return stk.top().first; 
    }
    
    int getMin() {
        return stk.top().second; 
    }
};


int main(int argc, char const *argv[])
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2

    return 0;
}
