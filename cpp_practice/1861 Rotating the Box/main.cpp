// https://leetcode.com/problems/rotating-the-box/description/

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

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int INPUT_ROWS = box.size(); 
        int INPUT_COLS = box[0].size(); 

        vector<vector<char>> res(INPUT_COLS, vector<char>(INPUT_ROWS, '.')); 

        // each row in box (increasing row idx) --> corresponds to column in res (decreasing in col idx)
        for (int row = 0; row < INPUT_ROWS; row++) { // process each row separately
            // populate res[??][INPUT_COLS - row]; 
            int stone_cnt = 0; 
            for (int elem = 0; elem < INPUT_COLS; elem++) {
                if (box[row][elem] == '*') {
                    // blocking item
                    res[elem][INPUT_COLS - row] = '*'; 
                    // populate stones before this element for this stone_cnt
                    int b_elem = elem-1; 
                    while (stone_cnt > 0) {
                        res[b_elem--][INPUT_COLS - row] = '#'; 
                        stone_cnt--; 
                    }
                } else if (box[row][elem] == '#') {
                    // movable stone
                    stone_cnt++; 
                } else {
                    // empty space '.'
                    continue;
                }
            }
            // we can still have leftover stones here... repopulate; 
            int b_elem = INPUT_COLS-1; 
            while (stone_cnt > 0) {
                res[b_elem--][INPUT_COLS - row] = '#'; 
                stone_cnt--; 
            }
        }

        return res; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
