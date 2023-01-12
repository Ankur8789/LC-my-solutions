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
    int ans;
    int f(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int l=f(root->left);
        int r=f(root->right);
        ans=max(ans,l+r+1);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root)
    {  ans=INT_MIN;
         f(root);
        return ans-1;
    }
};