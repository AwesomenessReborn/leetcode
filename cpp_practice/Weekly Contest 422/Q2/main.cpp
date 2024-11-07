
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

// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        unordered_set<pair<int, int>, pair_hash> visited; 

        int min = std::numeric_limits<int>::max(); 

        searchDepth(moveTime, visited, 0, 0, 0, min); 

        return min; 
    }
private: 
    void searchDepth(vector<vector<int>>& moveTime, unordered_set<pair<int, int>, pair_hash> &visited, int x, int y, int time, int &min) {

        if (x == moveTime.size() && y == moveTime[0].size()) {
            min = (time+1 < min) ? (time+1) : min; 
            return; 
        }

        if (visited.count(std::make_pair(x, y))) {
            return; 
        }
        
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
