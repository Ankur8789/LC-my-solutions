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
    int idx=0;
    TreeNode* f(int& idx,vector<int>& pre,int maxi){
        if(idx==pre.size() || pre[idx]>maxi)
            return nullptr;
        TreeNode* root=new TreeNode(pre[idx++]);
        root->left=f(idx,pre,root->val);
        root->right=f(idx,pre,maxi);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        return f(idx,pre,1e9);
    }
};