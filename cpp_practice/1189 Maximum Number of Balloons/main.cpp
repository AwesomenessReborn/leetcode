// https://leetcode.com/problems/maximum-number-of-balloons/

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

// cout << (int)'b' << endl; // 98 -- 1x
// cout << (int)'a' << endl; // 97 -- 1x
// cout << (int)'l' << endl; // 108 -- 2x
// cout << (int)'o' << endl; // 111 -- 2x
// cout << (int)'n' << endl; // 110 -- 1x

// balloon
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int hash[5] = {0};
        for (char c : text) {
            if (c - 'b' == 0) {
                hash[0]++;
                continue;
            }
            if (c - 'a' == 0) {
                hash[1]++;
                continue;
            }
            if (c - 'l' == 0) {
                hash[2]++;
                continue;
            }
            if (c - 'o' == 0) {
                hash[3]++;
                continue;
            }
            if (c - 'n' == 0) {
                hash[4]++;
                continue;
            }
        }

        int min = text.size();
        for (int i = 0; i < 5; i++) {
            if (i == 2 || i == 3) {
                min = min < (hash[i] / 2) ? min : (hash[i] / 2);
            }
            min = min < hash[i] ? min : hash[i];
        }

        return min;
    }
};

int main(int argc, char const *argv[])
{

    string s1 = "nlaebolko";
    string s2 = "loonbalxballpoon";
    string s3 = "leetcode";

    Solution sol;
    cout << sol.maxNumberOfBalloons(s1) << endl;
    cout << sol.maxNumberOfBalloons(s2) << endl;
    cout << sol.maxNumberOfBalloons(s3) << endl;

    return 0;
}
