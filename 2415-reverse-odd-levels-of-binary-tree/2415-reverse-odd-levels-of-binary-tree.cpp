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
  
    
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
       queue<TreeNode*> q;
        q.push(root);
        int emp=1;
        while(q.size()>0)
        {
            int sz=q.size();
            vector<TreeNode*> temp;
            vector<int> v;
            while(sz--)
            {
                TreeNode* t=q.front();
                q.pop();
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                v.push_back(t->val);
                temp.push_back(t);
            }
            if(emp<1)
                reverse(v.begin(),v.end());
            for(int i=0;i<v.size();i++)
            {
                temp[i]->val=v[i];
            }
            emp*=-1;
        }
        return root;
    }
};