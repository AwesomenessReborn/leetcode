

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

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        const int ROWS = grid.size(), COLS = grid[0].size(); 
        int maxcc = 0; 

        for (int row = 0; row < ROWS; row++ ) {

            for (int col = 0; col < COLS; col++) {
                maxcc = std::max(maxcc, dfs(row, col, grid, ROWS, COLS)); 
            }

        }

        return maxcc; 
    }
private: 
    int dfs(int row, int col, vector<vector<int>>& grid, int ROWS, int COLS) {
        if (row >= ROWS || col >= COLS || row < 0 || col < 0) return 0; 
        if (grid[row][col] == 0) return 0; 

        int temp = grid[row][col]; 
        grid[row][col] = 0;  

        return temp + dfs(row+1, col, grid, ROWS, COLS) 
            + dfs(row, col+1, grid, ROWS, COLS) 
            + dfs(row-1, col, grid, ROWS, COLS) 
            + dfs(row, col-1, grid, ROWS, COLS); 
    }
};

int main() {

    int x = 10;

    // Lambda capturing x by value (immutable by default)
    auto immutableLambda = [x]() {
        // x++; // Error: cannot modify x because it's captured as const
        cout << "Immutable x: " << x << endl;
    };

    // Lambda capturing x by value but allowing mutation using 'mutable'
    auto mutableLambda = [x]() mutable {
        x++;  // Allowed because of 'mutable'
        cout << "Mutable x inside lambda: " << x << endl;
    };

    immutableLambda();
    mutableLambda();

    // Original variable remains unchanged
    cout << "Original x after lambda: " << x << endl;

    return 0;
}