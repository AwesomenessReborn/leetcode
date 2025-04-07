// https://leetcode.com/problems/find-closest-number-to-zero/

#include <map>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>

using namespace std;

static auto _ = []()
{
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

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int clo = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (abs(nums[i]) < abs(clo))
                clo = nums[i];
            else if (abs(nums[i]) == abs(clo))
                clo = nums[i] > clo ? nums[i] : clo;
        }

        return clo;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 
    vector<int> nums1 = {-4, -2, 1, 4, 8};
    vector<int> nums2 = {2,-1,1};

    cout << "TEST 1: " << endl; 
    printArray(nums1); 
    cout << "result: \t" << sol.findClosestNumber(nums1) << endl; 
    cout << "exptected: \t" << "1" << endl; 
    cout << "\n"; 

    cout << "TEST 2: " << endl; 
    printArray(nums2); 
    cout << "result: \t" << sol.findClosestNumber(nums2) << endl; 
    cout << "exptected: \t" << "1" << endl; 
    cout << "\n"; 

    return 0;
}
