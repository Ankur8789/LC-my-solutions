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
    void f(TreeNode* root,int maxi,int mini,int& ans)
    {
        if(root==nullptr)
            return ;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        ans=max(ans,maxi-mini);
        f(root->left,maxi,mini,ans);
        f(root->right,maxi,mini,ans);
        
    }
    int maxAncestorDiff(TreeNode* root) 
    {
       int ans=0;
       f(root,root->val,root->val,ans);
       return ans;
    }
};