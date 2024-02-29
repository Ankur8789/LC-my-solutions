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
    bool isEvenOddTree(TreeNode* root) 
    {
       queue<TreeNode*> q;
       int lvl=1;
       q.push(root);
       while(q.size()>0)
       {
           int sz=q.size();
           int last=-1;
           // cout<<lvl<<"->";
           while(sz--)
           {
               TreeNode* temp=q.front();
               q.pop();
               // cout<<temp->val<<endl;
               if(temp->left)
                   q.push(temp->left);
               if(temp->right)
                   q.push(temp->right);
               if(lvl&1)
               {
                  if(!((temp->val)&1))
                      return 0;
                  if(last==-1)
                      last=temp->val;
                  else
                  {
                      if(temp->val>last)
                          last=temp->val;
                      else
                          return 0;
                  }
               }
               else
               {
                   if(((temp->val)&1))
                       return 0;
                   if(last==-1)
                       last=temp->val;
                   else
                   {
                       if(temp->val<last)
                           last=temp->val;
                       else
                           return 0;
                   }
               }
           }
           lvl++;
           last=-1;
       }
        return 1;
    }
};