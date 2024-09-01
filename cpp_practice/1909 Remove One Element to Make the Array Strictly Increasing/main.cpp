
#include <map>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// class Solution {
// public:
//     bool canBeIncreasing(vector<int>& nums) {
//         for (int i = 0; i < nums.size(); i++) {
//             int prev=-1; 
//             for (int j=0; j < nums.size(); j++) {
//                 if (j==i) {
//                     if (j == nums.size() - 1) return true; 
//                     continue;
//                 }
//                 if (nums[j] <= prev) break; 
//                 prev = nums[j]; 
//                 if (j == nums.size() - 1) return true; 
//             }
//         }
//         return false; 
//     }
// };

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int violations = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                violations++;
                if (violations > 1) return false;
                if (i > 1 && nums[i] <= nums[i - 2] && i + 1 < nums.size() && nums[i + 1] <= nums[i - 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};


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

int main(int argc, char const *argv[])
{
    Solution sol; 

    vector<int> nums1 = {1,2,10,5,7}; 
    vector<int> nums2 = {2,3,1,2}; 
    vector<int> nums3 = {1,1,1}; 
    vector<int> nums4 = {512,867,904,997,403}; 

    cout << "TEST 1: ";  
    cout << (sol.canBeIncreasing(nums1) ? "true" : "false") << endl;  
    cout << "expected: true " << endl << endl;  

    cout << "TEST 2: ";  
    cout << (sol.canBeIncreasing(nums2) ? "true" : "false") << endl;  
    cout << "expected: false " << endl << endl ;  

    cout << "TEST 3: ";  
    cout << (sol.canBeIncreasing(nums3) ? "true" : "false") << endl;  
    cout << "expected: false " << endl << endl;  

    cout << "TEST 4: ";  
    cout << (sol.canBeIncreasing(nums4) ? "true" : "false") << endl;  
    cout << "expected: true " << endl << endl;  

    return 0;
}
