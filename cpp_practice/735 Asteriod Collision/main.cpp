// https://leetcode.com/problems/asteroid-collision/description/?envType=study-plan-v2&envId=leetcode-75

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
#include <stack>

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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; 

        for (int asteriod : asteroids) {
            if (asteriod > 0) {
                st.push(asteriod); 
                continue;
            }

            bool is_destroyed = false; 

            while (!st.empty()) {
                int top = st.top(); 
                if (top < 0) break; 

                if (top < abs(asteriod)) {
                    st.pop(); 
                }
                else if (top == abs(asteriod)) {
                    st.pop(); 
                    is_destroyed = true; 
                } else {
                    is_destroyed = true; break; 
                }
            }

            if (!is_destroyed) st.push(asteriod); 
        }

        vector<int> res; 

        while (!st.empty()) {
            res.push_back(st.top()); 
            st.pop(); 
        }

        reverse(res.begin(), res.end()); 
        return res; 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
