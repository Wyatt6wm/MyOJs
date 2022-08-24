#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> res;
    
    void dfs(TreeNode* now)
    {
        if (now == nullptr)
            return;
        if (now->left != nullptr)
            dfs(now->left);
        if (now != nullptr)
            res.push_back(now->val);
        if (now->right != nullptr)
            dfs(now->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
};