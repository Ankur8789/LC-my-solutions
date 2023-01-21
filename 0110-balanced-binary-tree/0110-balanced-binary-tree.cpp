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
    int mx;
    int f(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int l=f(root->left);
        int r=f(root->right);
        mx=max(mx,abs(l-r));
        return max(l,r)+1;
        
    }
    bool isBalanced(TreeNode* root)
    {  
        mx=INT_MIN;
        int x=f(root);
        return mx<=1;
    }
};