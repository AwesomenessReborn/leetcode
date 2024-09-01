// https://leetcode.com/problems/merge-strings-alternately/

#include <map>
#include <iostream>
#include <string> 
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>

using namespace std;

static auto _ = []()
{
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
    string mergeAlternately(string word1, string word2) {
        
        char* ans = new char[word1.length() + word2.length() + 1]; 

        int x = 0; 
        int res_idx = 0; 
        while (1) {
            if (x == word1.length()) {
                while (x < word2.length()) {
                    ans[res_idx++] = word2.at(x++); 
                }
                ans[res_idx] = '\0'; 
                break; 
            }
            if (x == word2.length()) {
                while (x < word1.length()) {
                    ans[res_idx++] = word1.at(x++); 
                }
                ans[res_idx] = '\0'; 
                break; 
            }
            ans[res_idx++] = word1.at(x); 
            ans[res_idx++] = word2.at(x); 
            x++; 
        }
        std::string result(ans); 
        delete[] ans; 

        return result; 
        
    }
};

int main(int argc, char const *argv[])
{
    string w11 = "abc"; 
    string w12 = "pqr"; 
    string w21 = "ab"; 
    string w22 = "pqrs"; 
    string w31 = "abcd"; 
    string w32 = "pq"; 

    Solution sol; 
    cout << "TEST 1:  \t" << sol.mergeAlternately(w11, w12) << endl; 
    cout << "expected: \t" << "apbqcr" << endl << endl; 

    cout << "TEST 2:  \t" << sol.mergeAlternately(w21, w22) << endl; 
    cout << "expected: \t" << "apbqrs" << endl << endl; 

    cout << "TEST 3:  \t" << sol.mergeAlternately(w31, w32) << endl; 
    cout << "expected: \t" << "apbqcd" << endl << endl; 

    return 0;
}
