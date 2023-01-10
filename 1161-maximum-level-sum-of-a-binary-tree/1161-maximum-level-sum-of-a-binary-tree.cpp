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
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int mxsm=INT_MIN;
        int lvl=0;
        int k=1;
        while(q.size()>0)
        {
            int sz=q.size();
            int sm=0;
            while(sz--)
            {
                TreeNode* t=q.front();
                q.pop();
                sm+=t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                
            }
            if(sm>mxsm)
            {
                mxsm=sm;
                lvl=k;
            }
            k++;
        }
        return lvl;
    }
};