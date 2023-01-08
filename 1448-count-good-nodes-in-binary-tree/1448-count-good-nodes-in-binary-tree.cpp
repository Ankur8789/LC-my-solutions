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
    int f(TreeNode* root,int x)
    {
        if(root==nullptr)
            return 0;
        if(root->val>=x)
        {
            int a=f(root->left,root->val);
            int b=f(root->right,root->val);
            return a+b+1;
        }
        else
        {
            int a=f(root->left,x);
            int b=f(root->right,x);
            return a+b;
        }
    }
    int goodNodes(TreeNode* root) 
    {
        int ans=f(root,INT_MIN);
        return ans;
    }
};