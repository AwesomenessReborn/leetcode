// https://leetcode.com/problems/smallest-number-in-infinite-set/

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

// track all the values NOT in the set. 
class SmallestInfiniteSet {
private: 
    set<int> values; 
    int cur; 
public:
    SmallestInfiniteSet() {
        cur = 1; 
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    int popSmallest() {
        if (values.size()) {
            int res = *values.begin(); 
            values.erase(res); 
            return res; 
        } else {
            cur++; 
            return cur-1; 
        }
    }
    void addBack(int num) {
        if (cur > num) values.insert(num); 
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
int main(int argc, char const *argv[])
{


    return 0;
}
