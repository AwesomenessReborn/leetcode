// https://leetcode.com/problems/pascals-triangle-ii/description/?envType=problem-list-v2&envId=dynamic-programming

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
    vector<int> getRow(int rowIndex) {

        vector<int> row(rowIndex + 1, 0);
        row[0] = 1; // The first element is always 1

        for (int i = 1; i <= rowIndex; i++) {
            // Update row elements from right to left to avoid overwriting
            for (int j = i; j > 0; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};

int main(int argc, char const *argv[])
{
    Solution s; 

    printArray(s.getRow(3)); 

    return 0;
}
