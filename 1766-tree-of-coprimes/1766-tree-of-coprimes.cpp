class Solution
{
public:
    unordered_map<int, vector<int>> adj;
    vector<int> ans;
    unordered_map<int, int> vis;
    int cnt = 0;
    // int memo[51][51];

    void dfs(int u, int dis, vector<int> &nums, vector<vector<int>> &v)
    {

        vis[u] = 1;
        int val = -1;
        int ht = INT_MAX;
        for (int i = 1; i <= 50; i++)
        {
            if (v[i][0] != 1e9 && __gcd(nums[u], i) == 1)
            {
                if (ht > dis - v[i][0])
                {
                    ht = dis - v[i][0];
                    val = v[i][1];
                }
            }
        }
        vector<int> temp = v[nums[u]];
        ans[u] = val;
        v[nums[u]] = {dis, u};
        for (auto it : adj[u])
        {
            if (vis.find(it) == vis.end())
                dfs(it, dis + 1, nums, v);
        }
        v[nums[u]] = temp;
    }
    vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &ed)
    {
        for (auto t : ed)
        {
            int u = t[0];
            int v = t[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int n = nums.size();
        ans.resize(n);
        ans[0] = -1;
        // i , distance , kon hai
        vector<vector<int>> val(51, vector<int>(2, 1e9));
        dfs(0, 0, nums, val);

        // cout<<cnt<<endl;
        return ans;
    }
};