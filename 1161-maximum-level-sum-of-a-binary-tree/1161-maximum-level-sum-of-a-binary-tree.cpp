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
        int mx=INT_MIN,lvl=0,k=1;
       
        while(!q.empty())
        {     
            int sum=0;
            int sz=q.size();
            while(sz--)
            {
                TreeNode* t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(sum>mx)
            {
                mx=sum;
                lvl=k;
            }
            k++;
        }
        return lvl;
    }
};