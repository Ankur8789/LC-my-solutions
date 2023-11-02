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
    int cnt=0;
    pair<int,int> f(TreeNode* root)
    {
        if(root==nullptr)
            return {0,0};
        pair<int,int> p;
        p.first=0;
        p.second=0;
        if(root->left)
        {
            pair<int,int> le=f(root->left);
            p.first+=le.first;
            p.second+=le.second;
        }
        if(root->right)
        {
            pair<int,int> rt=f(root->right);
            p.first+=rt.first;
            p.second+=rt.second;
        }
        p.first+=root->val;
        p.second++;
        if((p.first/p.second)==root->val)cnt++;
        return p;
    }
    int averageOfSubtree(TreeNode* root) 
    {
        cnt=0;
        f(root);
        return cnt;
    }
};