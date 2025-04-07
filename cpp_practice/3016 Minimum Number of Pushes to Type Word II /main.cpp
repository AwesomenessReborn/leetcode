// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>

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

class Solution
{
public:
    int minimumPushes(string word)
    {
        int cfreq[26] = {0}; 
        
        for (char c : word) {
            cfreq[((int)c)-97]++; 
        }

        // create map -- freq -- chars: 
        map<int, vector<char>, std::greater<int>> freq; 
        for (int i = 0; i < 26; i++) {
            if (cfreq[i] > 0) freq[cfreq[i]].push_back((char)(i+97)); 
        }
        // high frequency should be assigned first -- cost at 1, the next 8 values should be cost 2. 
        // next 8 values should be cost 3, final 8 values should be cost 4. 
        
        int idx = 0; 
        int cost = 0; 
        for (auto it = freq.begin(); it != freq.end(); ++it) {
            for (char c : it->second) {
                cost += it->first * ((idx / 8) + 1); 
                idx++; 
            }
        }

        return cost; 
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "abcde";
    string s2 = "xyzxyzxyzxyz";
    string s3 = "aabbccddeeffgghhiiiiii";
    Solution sol;

    cout << "output   \t -- " << sol.minimumPushes(s1) << endl;
    cout << "expected \t -- " << "5" << endl;

    cout << "output   \t -- " << sol.minimumPushes(s2) << endl;
    cout << "expected \t -- " << "12" << endl;

    cout << "output   \t -- " << sol.minimumPushes(s3) << endl;
    cout << "expected \t -- " << "24" << endl;

    return 0;
}
