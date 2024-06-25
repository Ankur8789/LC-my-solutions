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
    int f(TreeNode* root,int upsum)
    {
        if(root==nullptr)
            return 0;
        int ri=f(root->right,upsum);
        int x =root->val;
        root->val+=ri;
        root->val+=upsum;
        int le=f(root->left,root->val);
        return x+le+ri;
        
    }
    TreeNode* bstToGst(TreeNode* root) 
    {
        f(root,0);
        return root;
        
    }
};