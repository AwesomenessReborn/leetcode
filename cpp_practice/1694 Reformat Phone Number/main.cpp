// https://leetcode.com/problems/reformat-phone-number/description/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using namespace std; 

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
    string reformatNumber(string number) {
        int nidx = 0; 
        int numcnt = 0; 
        while (nidx < number.length()) {
            if (number[nidx] != '-' && number[nidx] != ' ') {
                numcnt++; 
            }
            nidx++; 
        }
        nidx=0; 
        
        string ans; 
        ans.reserve(number.length()); 
        while (nidx < number.length()) {
            if (number[nidx] == '-' || number[nidx] == ' ') {
                nidx++; continue;
            }


        }

        return ans;  
    }
};

int main(int argc, char const *argv[])
{





    return 0;
}
