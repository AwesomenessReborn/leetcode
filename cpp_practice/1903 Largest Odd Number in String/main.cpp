// https://leetcode.com/problems/largest-odd-number-in-string/description/ 

#include <map>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    string largestOddNumber(string num) {
        int fin = 0; 
        int idx = 0; 
        bool odd = false; 
        while (idx < num.size()) {
            if ((((int)num[idx] - 48) % 2) == 1) {
                fin = idx;
                odd=true; 
            } 
            idx++; 
        }
        if (!odd) {return "";}
        return num.substr(0, fin + 1); 
    }
};

int main(int argc, char const *argv[])
{
    string num1 = "52"; 
    string num2 = "4206"; 
    string num3 = "35427"; 
    Solution sol; 

    cout << "TEST 1: \t"  << sol.largestOddNumber(num1) << endl; 
    cout << "Expected: \t" << "5" << endl << endl; 

    cout << "TEST 2: \t"  << sol.largestOddNumber(num2) << endl; 
    cout << "Expected: \t" << "" << endl << endl ; 

    cout << "TEST 3: \t"  << sol.largestOddNumber(num3) << endl; 
    cout << "Expected: \t" << "35427" << endl << endl; 

    return 0;
}
