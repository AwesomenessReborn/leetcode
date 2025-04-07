// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/?envType=daily-question&envId=2024-10-24

#include <stack>
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* constructTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == NULL) return nullptr; 

    TreeNode* root = new TreeNode(arr[0]); 
    queue<TreeNode*> q; 
    q.push(root); 

    int i = 1; 
    while (!q.empty() && i < arr.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != NULL) {
            current->left = new TreeNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < arr.size() && arr[i] != NULL) {
            current->right = new TreeNode(arr[i]);
            q.push(current->right);
        }
        i++;

    }

    return root; 
}

/** 
 * stack STL: 
 * 
 * top() -- access up element. 
 * size() -- keep track of size. 
 * 
 * push() -- add on top. 
 * pop() -- remove off top. 
 * 
 */
class Solution {
public:
    int minLength(string s) {
        std::stack<char> rr; 

        for (int i = 0; i < s.size(); i++) {
            if (!rr.empty())  {
                if (s[i] == 'B' && rr.top() == 'A') {
                    rr.pop(); 
                } else if (s[i] == 'D' && rr.top() == 'C') {
                    rr.pop(); 
                } else {
                    rr.push(s[i]) ;
                }
            } else {
                rr.push(s[i]); 
            }
        }

        return rr.size(); 
    }
};

int main(int argc, char const *argv[])
{
    string s1 = "ABFCACDB" ;
    string s2 = "ACBBD" ;

    Solution sol; 
    cout << sol.minLength(s1) << endl; 
    cout << sol.minLength(s2) << endl; 

    return 0;
}
