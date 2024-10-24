// https://leetcode.com/problems/flip-equivalent-binary-trees/?envType=daily-question&envId=2024-10-24

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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1a = {
        1,2,3,4,5,6,NULL,NULL,NULL,7,8
    }; 
    TreeNode* r1a = constructTree(n1a); 

    vector<int> n1b = {
        1,3,2,NULL,6,4,5,NULL,NULL,NULL,NULL,8,7
    }; 
    TreeNode* r1b = constructTree(n1b); 

    Solution sol; 
    cout << sol.flipEquiv(r1a, r1b) << endl; 
    

    return 0;
}
