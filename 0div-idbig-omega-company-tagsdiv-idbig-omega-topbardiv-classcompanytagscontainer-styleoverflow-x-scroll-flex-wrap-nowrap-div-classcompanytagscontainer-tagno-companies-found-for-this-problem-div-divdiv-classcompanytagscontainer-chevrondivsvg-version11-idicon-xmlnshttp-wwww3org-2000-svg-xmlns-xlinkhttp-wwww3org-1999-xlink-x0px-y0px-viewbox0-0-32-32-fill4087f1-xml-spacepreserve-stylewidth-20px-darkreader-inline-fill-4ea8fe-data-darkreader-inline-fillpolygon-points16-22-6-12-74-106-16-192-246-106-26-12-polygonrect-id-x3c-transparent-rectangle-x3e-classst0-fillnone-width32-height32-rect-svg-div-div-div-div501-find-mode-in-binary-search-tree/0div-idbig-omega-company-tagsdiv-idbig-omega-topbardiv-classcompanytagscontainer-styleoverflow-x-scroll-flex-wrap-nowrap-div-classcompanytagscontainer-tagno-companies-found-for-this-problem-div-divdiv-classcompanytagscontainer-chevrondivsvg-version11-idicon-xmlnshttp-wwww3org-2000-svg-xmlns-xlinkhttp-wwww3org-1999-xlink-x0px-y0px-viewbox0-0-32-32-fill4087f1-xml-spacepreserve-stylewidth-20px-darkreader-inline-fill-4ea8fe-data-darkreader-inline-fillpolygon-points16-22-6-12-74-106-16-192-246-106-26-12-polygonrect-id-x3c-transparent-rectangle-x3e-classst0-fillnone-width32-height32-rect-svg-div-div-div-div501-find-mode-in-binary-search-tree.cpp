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
    map<int,int> mp;
    void f(TreeNode* root)
    {
        if(root==nullptr)
            return;
        mp[root->val]++;
        f(root->left);
        f(root->right);
    }
    vector<int> findMode(TreeNode* root)
    {
        vector<int> ans;
        mp.clear();
        f(root);
        int maxi=0;
        for(auto t: mp)
         maxi=max(maxi,t.second);
        for(auto t: mp)
        {
           if(t.second==maxi)
               ans.push_back(t.first);
        }
        cout<<maxi<<endl;
        return ans;
    }
};