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
    int res = 0;

    void solve(TreeNode* node, bool goLeft, int cc) 
    {
        if (!node) return;
        res = max(res, cc);
        if (goLeft) 
        {
            solve(node->left, false, cc + 1);
            solve(node->right, true, 1);
        } 
        else 
        {
            solve(node->right, true, cc + 1);
            solve(node->left, false, 1);
        }
    }

    int longestZigZag(TreeNode* root) 
    {
        solve(root, true, 0);
        solve(root, false, 0);
        return res;
    }
};