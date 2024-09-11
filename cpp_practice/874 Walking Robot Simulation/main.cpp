// https://leetcode.com/problems/walking-robot-simulation/?envType=daily-question&envId=2024-09-04

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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;  
    }
};

struct pair_equal {
    template <class T1, class T2>
    bool operator() (const std::pair<T1, T2>& p1, const std::pair<T1, T2>& p2) const {
        return p1.first == p2.first && p1.second == p2.second;
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pair_hash, pair_equal> obsset; 
        for (vector<int> obs : obstacles) {
            obsset.insert(std::make_pair(obs[0], obs[1])); 
        }
        
        std::pair<int, int> curpos = {0, 0}; 
        int mdis = 0; 
        int dir = 0; // 0 north, 1 east(right), 2 south, 3 west(left)
        for (int command : commands) {
            switch (command)
            {
            case -2:
                if (dir == 0) {
                    dir = 3; 
                    break; 
                } 
                dir--; 
                break;
            case -1:   
                if (dir == 3) {
                    dir = 0; 
                    break; 
                }
                dir++; 
                break;  
            default: // all cases from [1, 9] inclusive. 
                for (int i = 0; i < command; i++) {
                    int dx = (dir == 0) ? 0 : ((-1)*(dir-2)); 
                    int dy = (dir == 3) ? 0 : ((-1)*(dir-1)); 

                    auto next = std::make_pair(curpos.first+dx, curpos.second+dy); 

                    if (obsset.count(next)) break; 

                    curpos = next; 
                }
                break;
            }
            mdis = max(mdis, (curpos.first * curpos.first) + (curpos.second * curpos.second)); 
        }

        // std::cout << "[" << curpos.first << ", " << curpos.second << "]" << endl; 
        return mdis; 
    }
};

int main(int argc, char const *argv[])
{   
    vector<int> n1 = {6,-1,-1,6}; 
    vector<vector<int>> o1 = {}; 
    Solution sol; 

    cout << sol.robotSim(n1, o1) << endl; 

    return 0;
}
