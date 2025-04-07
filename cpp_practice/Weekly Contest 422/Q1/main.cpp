

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
    bool isBalanced(string num) {
        
        int odd = 0; 
        int even = 0; 
        for (int i = 0; i < num.size(); i++) {
            if (i % 2 == 0) {
                even += (num[i] - 48); 
            } else {
                odd += (num[i] - 48); 
            }
        }
        return odd == even; 
    }
};


int main(int argc, char const *argv[])
{
    Solution sol; 
    cout << sol.isBalanced("1234") << endl; 
    cout << sol.isBalanced("24123") << endl; 

    return 0;

}

