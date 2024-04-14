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
class Solution
{
public:
    int sumLL(TreeNode *root, int x)
    {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right && x == 0)
        {
            return root->val;
        }
        return sumLL(root->left, 0) + sumLL(root->right, 1);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        return sumLL(root, 1);
    }
};