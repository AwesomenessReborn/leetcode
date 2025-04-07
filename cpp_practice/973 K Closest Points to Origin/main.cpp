// https://leetcode.com/problems/k-closest-points-to-origin/description/

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

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return (a.first * a.first + a.second * a.second) < (b.first * b.first + b.second * b.second);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(
            points.begin(), 
            points.begin() + k, 
            points.end(), 
            [] (const vector<int>&a, const vector<int>&b) {
                return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]); 
            }
        ); 

        return vector<vector<int>>(points.begin(), points.begin() + k); 
    }
};

// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         if (points.size() == k) return points; 
        
//         priority_queue<
//             std::pair<int, int>, 
//             std::vector<std::pair<int, int>>, 
//             Compare
//         > pointsq; 
//         for (auto& point : points) {
//             std::pair<int, int> curr = std::make_pair(point[0], point[1]); 
//             if (pointsq.size() < k) {
//                 pointsq.push(curr); 
//             } else if (Compare{}(curr, pointsq.top())) {
//                 pointsq.pop(); pointsq.push(curr); 
//             }
//         }

//         vector<vector<int>> ans; 
//         while (!pointsq.empty()) {
//             auto [x, y] = pointsq.top(); 
//             ans.push_back({x, y}); 
//             pointsq.pop();
//         }

//         return ans; 
//     }
// };

int main(int argc, char const *argv[])
{


    return 0;
}
