// https://leetcode.com/problems/rotate-image/description/

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

template <typename T>
void print2DArray(std::vector<std::vector<T>> values) {
    cout << "------------------------------" << endl; 
    for (int i = 0; i < values.size(); i++) {
        for (int j = 0; j < values[i].size(); j++) {
            std::cout << values[i][j] << "\t";  
        }
        std::cout << endl; 
    }
    cout << "------------------------------" << endl; 
} 

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int begin = 0, end = matrix.size()-1; 

//         while (end > begin) {
//             for (int i = 0; i < end - begin; i++) {
                
//                 int tmp = matrix[begin][begin + i]; 

//                 matrix[begin][begin + i] = matrix[end - i][begin]; 
//                 matrix[end - i][begin] = matrix[end][end - i]; 
//                 matrix[end][end - i] = matrix[begin + i][end]; 
//                 matrix[begin + i][end] = tmp;

//             }
//             end--; begin++; 
//         }
//     }
// };

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dimSize = matrix.size(); 
        for (int i = 0; i < dimSize; i++) {
            for (int j = i; j < dimSize; j++) {
                swap(matrix[i][j], matrix[j][i]); 
            }
            reverse(matrix[i].begin(), matrix[i].end()); 
        }
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> m1 = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    }; 
    std::vector<std::vector<int>> m2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    cout << "before: " << endl; 
    print2DArray(m1); 
    // print2DArray(m2); 

    Solution sol; 
    sol.rotate(m1); 
    // sol.rotate(m2); 
    cout << endl; 
    cout << "after: " << endl; 
    print2DArray(m1); 
    // print2DArray(m2); 

    return 0;
}
