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
    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        if(root==nullptr)
            return root;
        if(root->left==nullptr && root->right==nullptr)
        {
            if(root->val==target)
                return nullptr;
            else
                return root;
        }
        TreeNode* le = removeLeafNodes(root->left,target);
        TreeNode* ri = removeLeafNodes(root->right,target);
        root->left=le;
        root->right=ri;
        if(le==nullptr && ri==nullptr)
        {
            if(root->val==target)
                return nullptr;
            else
                return root;
        }
        else
            return root;
    }
};