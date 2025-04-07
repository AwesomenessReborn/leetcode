// https://leetcode.com/problems/valid-sudoku/description/

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


struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

/**
 * use single int value for hash. 
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        uint16_t hash; 
        char cc; 
        for (int i = 0; i < 9; i++) {
            hash = 0; 
            for (int j = 0; j < 9; j++) {
                cc = board[i][j]; 
                if (cc == '.') continue;

                // check if value already present. 
                int cur = (int)(cc-'0'); 
                if (hash & (1 << cur)) return false; 

                hash = hash | (1 << cur); 
            }
        }

        for (int i = 0; i < 9; i++) {
            hash = 0; 
            for (int j = 0; j < 9; j++) {
                cc = board[j][i]; 
                if (cc == '.') continue;

                // check if value already present. 
                int cur = (int)(cc-'0'); 
                if (hash & (1 << cur)) return false; 

                hash = hash | (1 << cur); 
            }
        }

        for (int i = 0; i < 7; i+=3) {
            for (int j = 0; j < 7; j+=3) {
                hash = 0; 

                for (int xdiff = 0; xdiff < 3; xdiff++) {
                    for (int ydiff = 0; ydiff < 3; ydiff++) {
                        cc = board[i+xdiff][j+ydiff]; 
                        if (cc == '.') continue;

                        int cur = (int)(board[i+xdiff][j+ydiff]-'0'); 
                        if (hash & (1 << cur)) return false; 

                        hash = hash | (1 << cur); 
                    }
                }
            }
        }

        return true; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
