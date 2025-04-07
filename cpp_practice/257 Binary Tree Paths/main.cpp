// https://leetcode.com/problems/binary-tree-paths/?envType=problem-list-v2&envId=backtracking&difficulty=EASY

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths; 
        vector<int> cur_path; 
        backtrack(root, cur_path, paths); 
        return paths; 
    }
private: 
    void backtrack(TreeNode* root, vector<int> &path, vector<string> &paths) {
        if (root == nullptr) return; 

        path.push_back(root->val); 

        if (root->left == nullptr && root->right == nullptr)  {
            string ent = ""; 
            for (int i = 0; i < path.size(); i++) {
                ent += std::to_string(path[i]); 
                if (i != path.size()-1) ent += "->"; 
            }
            paths.push_back(ent); 
            return; 
        }

        // search root left. 
        if (root->left != nullptr) backtrack(root->left, path, paths); 
        // search root right. 
        if (root->right != nullptr) backtrack(root->right, path, paths); 

        // once finished subpaths, pop last element. 
        path.pop_back(); 
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
