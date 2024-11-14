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
    bool f(TreeNode* root,int k,map<int,int>& mp){
        if(root==nullptr)
            return false;
        if(mp.count(k-root->val))
            return 1;
        mp[root->val]++;
       return f(root->left,k,mp) | f(root->right,k,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int> mp;
        return f(root,k,mp);
    }
};