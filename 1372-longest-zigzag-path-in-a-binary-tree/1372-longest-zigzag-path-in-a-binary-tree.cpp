class Solution {
public:
    int res;
    void f(TreeNode* root,int dir,int cc)
    {
        if(root==nullptr)
            return;
        res=max(res,cc);
        if(dir!=1)
        {
            f(root->right,1,cc+1);
            f(root->left,0,1);
        }
        if(dir!=0)
        {
            f(root->left,0,cc+1);
            f(root->right,1,1);
        }
            
    }
    int longestZigZag(TreeNode* root)
    {
        res=-1e9;
        f(root,-1,0);
        return res;
    }
};