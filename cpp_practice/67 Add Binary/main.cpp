// https://leetcode.com/problems/add-binary/?envType=problem-list-v2&envId=eofbf01i

#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

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

class Solution {
public:
    string addBinary(string a, string b) {
        string res; 
        int i = a.size()-1, j = b.size()-1; 

        int carry = 0; 
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0'; if (j >= 0) sum += b[j--] - '0';  // Convert char to int and add

            carry = sum / 2; 
            res += (sum % 2) + '0'; 
        }

        reverse(res.begin(), res.end()); 

        return res; 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 
    cout  << sol.addBinary("11", "1") << endl; 

    return 0;
}
