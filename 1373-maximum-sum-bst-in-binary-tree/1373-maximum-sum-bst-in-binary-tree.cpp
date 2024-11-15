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
    int ans=0;
    vector<int> f(TreeNode* root){
        if(root==nullptr)
            return {0,INT_MAX,INT_MIN};
        vector<int> le=f(root->left);
        vector<int> ri=f(root->right);
        cout<<le[0]+ri[0]+root->val<<endl;
        if(le[2]<root->val && ri[1]>root->val){
            ans=max(ans,le[0]+ri[0]+root->val);
            return {le[0]+ri[0]+root->val , min(le[1],root->val),max(ri[2],root->val)};
        }
        else{
            return {max({le[0],ri[0]}),INT_MIN,INT_MAX};
        }
    }
    int maxSumBST(TreeNode* root) {
       vector<int> res=f(root); // sum min max
       return ans;
    }
};