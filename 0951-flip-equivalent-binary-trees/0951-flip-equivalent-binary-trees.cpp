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
    bool flipEquiv(TreeNode* r1, TreeNode* r2) {
        if((r1 == nullptr && r2 != nullptr) || (r2 == nullptr && r1 != nullptr))
            return false;
        if(r1 == nullptr && r2 == nullptr)
            return true;
        if(r1 -> val != r2 -> val)
            return false;
        bool ans1 = true , ans2 = true;
        ans1 &= flipEquiv(r1 -> left , r2 -> right);
        ans1 &= flipEquiv(r1 -> right, r2 -> left);
        ans2 &= flipEquiv(r1 -> left , r2 -> left);
        ans2 &= flipEquiv(r1 -> right, r2 -> right);
        return (ans1 || ans2);
    }
};