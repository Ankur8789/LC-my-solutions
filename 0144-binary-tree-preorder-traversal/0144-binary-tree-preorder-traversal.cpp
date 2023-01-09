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
    vector<int> x;
    void f(TreeNode* root)
    {
        if(root==nullptr)
            return ;
        x.push_back(root->val);
        f(root->left);
        f(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        x.clear();
        f(root);
        return x;
    }
};