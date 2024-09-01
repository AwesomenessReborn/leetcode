// https://leetcode.com/problems/furthest-building-you-can-reach/

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
#include <queue>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

struct CompareDistance {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
    }
};

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return (a.first * a.first + a.second * a.second) > (b.first * b.first + b.second * b.second);
}


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

/**
 * maintain vector of pairs
 * heapify --> 
 *      maintain pair<gain, location> 
 * need to sort the gains, and use the max gains for ladders... 
 */
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int, vector<int>, std::greater<int>> llen; 
        for (int i = 1; i < heights.size(); i++) {
            int diff = heights[i] - heights[i-1]; 

            if (diff <= 0) continue; 

            if (llen.size() < ladders) {
                llen.push(diff); 
                continue;
            }

            if (!llen.empty() && diff > llen.top()) {
                bricks -= llen.top(); 
                llen.pop(); 
                llen.push(diff); 
            } else {
                bricks -= diff; 
            }

            if (bricks < 0) return i - 1; 
        }

        return heights.size() - 1; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {14,3,19,3}; 
    Solution sol; 
    cout << sol.furthestBuilding(n1, 17, 0) << endl; 

    return 0;
}
