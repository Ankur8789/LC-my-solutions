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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int k=1;
        while(q.size()>0)
        {
            int sz=q.size();
            vector<int> temp;
            while(sz--)
            {
                TreeNode* t=q.front();
                temp.push_back(t->val);
                if(t->left!=NULL)
                    q.push(t->left);
                if(t->right!=NULL)
                    q.push(t->right);
                q.pop();
            }
            if(k==1)
                ans.push_back(temp);
            else
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            k*=-1;
        }
        return ans;
        
    }
};