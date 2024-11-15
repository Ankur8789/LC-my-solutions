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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> mp;
        queue<pair<pair<int,int>,TreeNode*>> q;
        // row col
        q.push({{0,0},root});
        // mp[0].push_back({0,root->val});
        while(q.size()){
            auto p=q.front();
            q.pop();
            auto t=p.first;
            int row=t.first,col=t.second;
            TreeNode* temp=p.second;
            mp[col].push_back({row,p.second->val});
            if(temp->left)
                q.push({{row+1,col-1},temp->left});
            if(temp->right)
                q.push({{row+1,col+1},temp->right});
        }
        for(auto& x: mp){
           sort(x.second.begin(),x.second.end());
            vector<int> res;
           for(auto y:x.second)
               res.push_back(y.second);
           ans.push_back(res);
        }
        return ans;
    }
};