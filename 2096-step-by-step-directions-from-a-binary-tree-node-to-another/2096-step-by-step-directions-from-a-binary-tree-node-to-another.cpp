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
    TreeNode* lcaval;
    int lcaDist=0;
    TreeNode * LCA(TreeNode* root,int sv,int ev)
    {
        if(root==nullptr)
            return root;
        if(root->val==sv || root->val==ev)
            return root;
        TreeNode * le=LCA(root->left,sv,ev);
        TreeNode * ri=LCA(root->right,sv,ev);
        if(le && ri)
            return root;
        else if(le)
            return le;
        else return ri;
    }
    void f(TreeNode* root,int sv,int ev,string& dest,int& depths,int& depthd,int d,string& temp)
    {
        if(root==nullptr)
            return;
        if(root->val==sv || root->val==ev)
        {
            if(root->val==sv)
            {
               depths=d; 
            }
            else
            {
                dest=temp;
                depthd=d;
            }
        }
        if(root==lcaval)
            lcaDist=d;
        temp+='L';
        f(root->left,sv,ev,dest,depths,depthd,d+1,temp);
        temp.pop_back();
        temp+='R';
        f(root->right,sv,ev,dest,depths,depthd,d+1,temp);
        temp.pop_back();
    }
    string getDirections(TreeNode* root, int sv, int ev)
    {
       TreeNode* lca=LCA(root,sv,ev); 
       lcaval=lca;
       if(lca->val==sv || lca->val==ev)
       {
           string dest="",temp="";
           int depths=0,depthd=0;
           f(root,sv,ev,dest,depths,depthd,0,temp);
           string ans="";
           if(depths>depthd)
           {
               while(depths>depthd)
                   ans+='U',depths--;
           }
           else
           {
               ans=dest.substr(depths);
           }
           return ans;
       }
       else
       {
           string dest="",temp="";
           int depths=0,depthd=0;
           f(root,sv,ev,dest,depths,depthd,0,temp);
           string ans="";
           while(depths>lcaDist)
               ans+='U',depths--;
           ans+=dest.substr(lcaDist);
           return ans;
       }
    }
};