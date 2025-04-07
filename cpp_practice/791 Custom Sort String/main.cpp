// https://leetcode.com/problems/custom-sort-string/?envType=problem-list-v2&envId=eofbf01i

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

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> rec; 

        for (char c : s) {
            rec[c]++; 
        }

        string res;
        for (char c : order) {
            if (rec.count(c)) { 
                res += string(rec[c], c); 
                rec.erase(c); 
            }
        }

        for (auto it : rec) {
            res += string(it.second, it.first); 
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    string o1 = "cba"; 
    string o2 = "bcafg"; 

    string s1 = "abcd"; 
    string s2 = "abcd"; 

    Solution sol; 

    cout << "T1: " << sol.customSortString(o1, s1) << endl; 
    cout << "T2: " << sol.customSortString(o2, s2) << endl; 

    return 0;
}
