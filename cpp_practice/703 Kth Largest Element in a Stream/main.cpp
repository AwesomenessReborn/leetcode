// https://leetcode.com/problems/kth-largest-element-in-a-stream/

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



class KthLargest {
public:
    int k; 
    vector<int> values; 
    KthLargest(int k, vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); 
        this->values = nums; 
        this->k = k; 
    }
    
    int add(int val) {
        int left = 0;
        int right = this->values.size();

        while (left < right) {
            int mid = (left + right) / 2;

            if (this->values[mid] < val) {
                left = mid + 1; 
            } else {
                right = mid; 
            }
        } // left is the target. 

        // binary search to target --> and then insert. 
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char const *argv[])
{


    return 0;
}
