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
    void f(TreeNode* root,vector<int>& x)
    {
        if(root==NULL)
        return ;
        if(root->left==nullptr && root->right==nullptr)
        {
            x.push_back(root->val);
            return ;
        }
        f(root->left,x);
        f(root->right,x);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> a,b;
        f(root1,a);
        f(root2,b);
        if(a==b)
        return true;
        else
        return false;
    }
};