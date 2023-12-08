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
    string str="";
    void f(TreeNode* root)
    {
        if(root==NULL)
            return;
        str+=to_string(root->val);
         if(root->right && root->left)
         {
             str+='(';
             f(root->left);
             str+=')';
             str+='(';
             f(root->right);
             str+=')';
         }
        else if(root->left==NULL && root->right!=NULL)
        {
            str+="()";
            str+='(';
            f(root->right);
            str+=')';
            
        }
        else if(root->left!=NULL && root->right==NULL)
        {
             str+='(';
            f(root->left);
            str+=')';
        }
        
    }
    
    string tree2str(TreeNode* root) 
    {
        f(root);
        return str;
    }
};