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
       int res=-1e5,ans=0;
       int lvl=1;
       queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0)
        {
            int sz=q.size();
            int sum=0;
            while(sz--)
            {
                TreeNode *t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(sum>res)
            {
                res=sum;
                ans=lvl;
            }
            lvl++;
        }
        // cout<<
        return ans;
    }
};