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
    int minSwaps(vector<int>& nums, int n){
            int len = n;
            map<int, int> map;
            for (int i = 0; i < len; i++)
                map[nums[i]] = i;

            sort(nums.begin(), nums.end());
            vector<bool> visited(n);
            int ans = 0;
            for (int i = 0; i < len; i++) {
                if (visited[i] || map[nums[i]] == i)
                    continue;
                int j = i, cycle_size = 0;
                while (!visited[j]) {
                    visited[j] = true;
                    j = map[nums[j]];
                    cycle_size++;
                }
                if (cycle_size > 0) {
                    ans += (cycle_size - 1);
                }
            }
            return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(q.size()>0){
            int sz=q.size();
            vector<int> temp;
            while(sz--){
               TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                q.push(t->right);                
            }
            ans+=minSwaps(temp,temp.size());
        }
        return ans;
    }
};