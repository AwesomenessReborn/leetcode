// https://leetcode.com/problems/pascals-triangle/description/?envType=problem-list-v2&envId=dynamic-programming

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

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; 

        if (numRows == 0) return ans; 
        ans.push_back({1}); 
        if (numRows == 1) {
            return ans; 
        }
        ans.push_back({1, 1}); 
        if (numRows == 2) {
            return ans; 
        }

        for (int i = 2; i < numRows; i++) { 
            vector<int> row; 
            row.reserve(i+1); 

            if (i % 2 == 1) {
                row.push_back(1); 
                for (int j = 1; j < (i+1)/2; j++) {
                    row.push_back(ans[i-1][j-1] + ans[i-1][j]); 
                }
                for (int j = row.size()-1; j>=0; j--) {
                    row.push_back(row[j]); 
                }
            } else {
                row.push_back(1); 
                for (int j = 1; j <= (i)/2; j++) {
                    row.push_back(ans[i-1][j-1] + ans[i-1][j]); 
                }
                for (int j = row.size()-2; j>=0; j--) {
                    row.push_back(row[j]);  
                }
            }
            ans.push_back(row); 
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{
    Solution s; 
    // printDoubleArray(s.generate(1)); 
    // printDoubleArray(s.generate(2)); 
    // printDoubleArray(s.generate(3)); 
    printDoubleArray(s.generate(6)); 
    // printDoubleArray(s.generate(10)); 

    cout << endl; 
    return 0;

}
