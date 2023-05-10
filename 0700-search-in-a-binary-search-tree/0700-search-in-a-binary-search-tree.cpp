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
    TreeNode* temp;
    void trav(TreeNode* root,int val)
    {
        if(root==nullptr)
            return;
        if(root->val==val)
        {
            temp=root;
            return;
        }
        trav(root->left,val);
        trav(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        trav(root,val);
        return temp;
    }
};