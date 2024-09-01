
#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std; 

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans; 
        unordered_map<int, int> freq; // value : freq 

        for (int i = 0; i < nums.size(); i++) {
            auto it = freq.insert(std::pair<int, int>(nums[i], 1)); 
            if (!it.second) {
                it.first->second++;  
            }
        }

        map<int, std::set<int, std::greater<int>>> rfreq; // freq : value

        for (auto &&i : freq)
        {
            auto it = rfreq.insert(std::make_pair(i.second, std::set<int, std::greater<int>>{i.first})); 
            if (!it.second) {
                it.first->second.insert(i.first); 
            }
        }

        for (const auto &entry : rfreq) {
            for (const auto &elem : entry.second) {
                for (int i = 0; i < entry.first; i++) {
                    ans.push_back(elem); 
                }
            }
        }

        return ans; 
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
    vector<int> nums1 = {1,1,2,2,2,3}; 
    vector<int> nums2 = {2,3,1,3,2}; 
    vector<int> nums3 = {-1,1,-6,4,5,-6,1,4,1}; 

    cout << "TEST 1: before" << endl; 
    printArray(nums1); 
    cout << "after" << endl; 
    printArray(sol.frequencySort(nums1)); 
    cout << "\n"; 

    cout << "TEST 2: before" << endl; 
    printArray(nums2); 
    cout << "after" << endl; 
    printArray(sol.frequencySort(nums2)); 
    cout << "\n"; 

    cout << "TEST 3: before" << endl; 
    printArray(nums3); 
    cout << "after" << endl; 
    printArray(sol.frequencySort(nums3)); 
    cout << "\n"; 

    return 0;
}
