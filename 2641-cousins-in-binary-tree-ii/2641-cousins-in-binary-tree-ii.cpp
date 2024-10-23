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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*,int> vals,finsum;
        map<TreeNode*,TreeNode*> par;
        par[root] = nullptr;
        while(q.size() > 0){
            auto sz = q.size();
            int sum = 0;
            vector<TreeNode*> vec;
            while(sz--){
                auto u = q.front();
                q.pop();
                vec.push_back(u);
                sum += u -> val;
                vals[par[u]] += u -> val;
                if(u -> left)
                    q.push(u -> left) ,par[u -> left] = u;
                if(u -> right)
                    q.push(u -> right), par[u -> right] = u;
            }
            for(auto x: vec){
                finsum[x] = sum - vals[par[x]];
            }
        }
        for(auto x : finsum){
            x.first -> val = x.second;
        }
        return root;
    }
};