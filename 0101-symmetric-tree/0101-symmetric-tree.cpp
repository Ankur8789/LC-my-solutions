class Solution {
    bool isMirror(TreeNode* a, TreeNode* b) {
        if (a == nullptr || b == nullptr) 
            return a == b;
        if (a->val != b->val)
            return false;
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }
};