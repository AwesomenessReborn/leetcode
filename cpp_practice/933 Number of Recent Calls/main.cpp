// https://leetcode.com/problems/number-of-recent-calls/

#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

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


class RecentCounter {
private: 
    vector<int> rcalls; 
    int begin; 
public:
    RecentCounter() {
        rcalls = {}; 
        begin = 0; 
    }
    int ping(int t) {
        rcalls.push_back(t); 
        while (t > rcalls[begin] + 3000) {
            begin++; 
        }
        return rcalls.size()-begin; 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main(int argc, char const *argv[])
{



    return 0;
}
