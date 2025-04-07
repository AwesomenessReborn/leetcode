// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/description/?envType=daily-question&envId=2024-10-22

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

struct GreaterValue {
    bool operator()(const int &a, const int &b) {
        return a > b; 
    }
};

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> record; 

        dig(root, 0, record); 
        if (record.size() < k) return -1; 

        priority_queue<long long, vector<long long>, greater<long long>> hp; 

        for (long long sum : record) {
            hp.push(sum); 
            if (hp.size() > k) {
                hp.pop(); 
            }
        }

        return hp.top(); 
    }
private: 
    void dig(TreeNode* root, int level, vector<long long> &sumsque) {
        if (root == nullptr) return; 

        if  (level >= sumsque.size()) {
            sumsque.push_back(0); 
        }

        sumsque[level] += root->val; 

        dig(root->left, level+1, sumsque); 
        dig(root->right, level+1, sumsque); 
    }
};

int main(int argc, char const *argv[])
{


    return 0;
}
