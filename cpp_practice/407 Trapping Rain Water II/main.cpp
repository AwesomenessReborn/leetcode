// https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-01-19

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
#include <climits>
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

struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}

// return index of target: 
int binSearch(vector<int> arr, int x) {

    int left = 0, right = arr.size()-1; 
    int mid; 

    while (left <= right) {
        mid = left + (right - left) / 2; 

        if (arr[mid] == x) {
            return mid; 
        } else if (arr[mid] > x) {
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    if (right < 0) return 0; 
    if (left >= arr.size()) return arr.size() - 1; 

    if (abs(arr[left]-x) < abs(arr[right] - x)) {
        return left; 
    } else {
        return right; 
    }
}


using hMapPair = array<int, 3>; 

struct Compare {
    bool operator()(const hMapPair& a, const hMapPair& b) {
        return a[0] > b[0]; 
    }
}; 

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int ROWS = heightMap.size(), COLS = heightMap[0].size(); 

        if (ROWS <= 2 || COLS <= 2) return 0; 

        vector<vector<bool>> seen(ROWS, vector<bool>(COLS, false)); 
        priority_queue<hMapPair, vector<hMapPair>, Compare> boundary; 
        int cc = 0; 

        int directions[4][2] = {
            {0, -1}, 
            {0, 1}, 
            {-1, 0},  
            {1, 0}
        }; 

        for (int i = 0; i < ROWS; i++) {
            seen[i][0] = true; 
            seen[i][COLS-1] = true; 

            boundary.push({heightMap[i][0], i, 0}); 
            boundary.push({heightMap[i][COLS-1], i, COLS-1}); 
        }

        for (int i = 0; i < COLS; i++) {
            seen[0][i] = true; 
            seen[ROWS-1][i] = true; 

            boundary.push({heightMap[0][i], 0, i}); 
            boundary.push({heightMap[ROWS-1][i], ROWS-1, i}); 
        }

        printDoubleArray(seen); 

        while (!boundary.empty()) {
            const auto min = boundary.top();

            int height=min[0], x=min[1], y=min[2]; 
            boundary.pop(); 

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + directions[dir][0]; 
                int ny = y + directions[dir][1]; 

                if (nx >= ROWS || ny < 0 || nx < 0 || ny >= COLS) {
                    continue;
                }
                if (seen[nx][ny]) continue;

                int nHeight = heightMap[nx][ny]; 

                if (nHeight < height) {
                    cc += height - nHeight; 
                }

                boundary.push({std::max(nHeight, height), nx, ny}); 
                seen[nx][ny] = true; 
            }

        }

        return cc; 
    }
};

int main() {
    vector<vector<int>> n1 = {
        {
            1,4,3,1,3,2
        }, 
        {
            3,2,1,3,2,4
        }, 
        {
            2,3,3,2,3,1
        }
    }; 


    Solution s; 

    cout << s.trapRainWater(n1) << endl; 

    
    return 0;   
}
