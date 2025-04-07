// https://leetcode.com/problems/circular-sentence/?envType=daily-question&envId=2024-11-02

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
    bool isCircularSentence(string sentence) {

        if (*sentence.begin() != sentence.back()) return false; 
        
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ') {
                if (sentence[i-1] != sentence[i+1]) return false; 
            }
        }

        return true; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
