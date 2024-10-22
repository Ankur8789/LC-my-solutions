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
    typedef long long ll;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        vector<ll> res;
        q.push(root);
        while(q.size() > 0){
            ll sz = q.size(), sum = 0;
            while(sz--){
                auto pr = q.front();
                q.pop();
                sum += pr->val;
                if(pr -> left)
                    q.push(pr -> left);
                if(pr -> right)
                    q.push(pr -> right);
            }
            res.push_back(sum);
        }
        sort(begin(res), end(res));
        reverse(begin(res), end(res));
        if(res.size() < k)
            return -1;
        else
            return res[k-1];
    }
};