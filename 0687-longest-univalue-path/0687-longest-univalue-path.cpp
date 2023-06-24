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
    int ansx=0;
    int f(TreeNode* root)
    {
       if(root==nullptr)
           return 0;
       int l=f(root->left);
       int r=f(root->right);
       if(root->left && root->left->val==root->val)
           l++;
       else
           l=0;
       if(root->right && root->right->val==root->val)
           r++;
       else
            r=0;
       ansx=max(ansx,l+r);
       return max(l,r);
       
        
    }
    int longestUnivaluePath(TreeNode* root)
    {
       int ans=f(root);
       return ansx;
    }
};