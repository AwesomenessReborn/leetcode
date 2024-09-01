// https://leetcode.com/problems/leaf-similar-trees/

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2; 
        r1.reserve(200); r2.reserve(200); 

        scan(root1, &r1); 
        scan(root2, &r2); 

        if (r1.size() != r2.size()) return false; 

        for (int idx = 0; idx < r1.size(); idx++) {
            if (r1[idx] != r2[idx]) return false; 
        }
        return true;
    }
private: 
    void scan(TreeNode* root, vector<int>*leaves) {
        if (root->left == nullptr && root->right == nullptr) {
            leaves->push_back(root->val); 
            return; 
        }
        if (root->left != nullptr) scan(root->left, leaves); 
        if (root->right != nullptr) scan(root->right, leaves); 
    }
};


int main(int argc, char const *argv[])
{
    return 0;
}
