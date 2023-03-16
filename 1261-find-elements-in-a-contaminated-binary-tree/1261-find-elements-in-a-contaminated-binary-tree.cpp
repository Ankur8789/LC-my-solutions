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
class FindElements {
public:
    bool mila;
    TreeNode* t;
    void f(TreeNode* root,int cc)
    {
        if(root==nullptr)
            return ;
        root->val=cc;
        f(root->left,2*cc+1);
        f(root->right,2*cc+2);
    }
    void khoj(TreeNode* root,int cc)
    {
        if(root==nullptr)
            return ;
        if(root->val==cc)
            mila=true;
        khoj(root->left,cc);
        khoj(root->right,cc);
    }
    FindElements(TreeNode* root) 
    {
       t=root;
        f(root,0);
    }
    
    bool find(int target) 
    {
        mila=false;
        khoj(t,target);
        return mila;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */