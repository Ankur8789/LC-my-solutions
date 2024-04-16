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
    void f(TreeNode * root , int val ,int depth ,int curr)
    {
        if(root == nullptr)
            return ;
        if(depth == curr)
        {
            TreeNode * le = new TreeNode(val);
            TreeNode * ri = new TreeNode(val);
            le -> left = root -> left;
            ri ->right = root -> right;
            root -> left = le;
            root -> right = ri;
            return ;
        }
        f(root->left , val , depth , curr+1);
        f(root->right , val , depth , curr+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth == 1)
        {
            TreeNode * newr = new TreeNode(val);
            newr -> left = root;
            return newr;
        }
        f(root , val , depth - 1 ,1);
        return root;
    }
};