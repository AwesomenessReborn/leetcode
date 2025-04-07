// https://leetcode.com/problems/largest-palindromic-number/description/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <climits>

using namespace std;

static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

template <typename T>
void printArray(std::vector<T> values)
{
    std::cout << "[";
    for (int i = 0; i < values.size(); i++)
    {
        std::cout << values[i];
        if (values.size() - 1 > i)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// class Solution {
// public:
//     string largestPalindromic(string num) 
//     {
//         map<char,int>mp;
//         for(char ch:num) mp[ch]++;

//         int mx = INT_MIN;
//         for(auto [a, b]:mp)
//         {
//             if(b%2)
//             {
//                 mp[a]--;
//                 mx = max(mx, a-'0');
//             }
//         }

//         deque<char>opps;
//         if(mx != INT_MIN) opps.push_back(mx + '0');

//         for(auto [a, b]:mp)
//         {
//             while(b)
//             {
//                 opps.push_back(a);
//                 opps.push_front(a);
//                 b -= 2;
//             }
//         }

//         while(opps.size() > 1 and opps.front()=='0') opps.pop_front();
//         while(opps.size() > 1 and opps.back()=='0') opps.pop_back();

//         string ans;
//         for(auto ch:opps) ans += ch;
//         return ans;
//     }
// };

class Solution {
public:
    string largestPalindromic(string num) {
        int dig[10] = {0}; 
        for (char d : num) {
            dig[d-'0']++; 
        }
        map<int, vector<int>, std::greater<int>> freq; 
        for (int i = 0; i < 10; i++) {
            freq[dig[i]].push_back(i); 
        }


        
        std::deque<char> result; 
        int max_mid = -1; 
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            // DEBUG: 
            cout << "freq: " << it->first << endl; 
            cout << "values: "; 
            printArray(it->second); 

            int count = it->first; 
            for (int digit : it->second) {
                while (count >= 2) {
                    result.push_back(digit + '0'); 
                    result.push_front(digit + '0'); 
                    count-= 2; 
                }
                if (count == 1) {
                    max_mid = max(max_mid, digit); 
                }
            }
        }
        
        if (max_mid >= 0) result.insert(result.begin() + (result.size() / 2), (char)(max_mid+'0')); 
        while (result.size() > 1 && result.front() == '0') result.pop_front(); 
        while (result.size() > 1 && result.back() == '0') result.pop_back(); 

        return std::string(result.begin(), result.end()); 
    }
};

int main(int argc, char const *argv[])
{
    string n1 = "444947137"; 
    string n2 = "00009"; 
    string n3 = "00001105"; 
    string n4 = "5736732"; 

    Solution sol; 
    cout << sol.largestPalindromic(n1) << endl; 
    cout << sol.largestPalindromic(n2) << endl; 
    cout << sol.largestPalindromic(n3) << endl; 
    cout << sol.largestPalindromic(n4) << endl; 

    return 0;
}
