class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>> adj;
        vector<int> ideg(n);
        for(auto x : edges)
        {
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ideg[u] += 1;
            ideg[v] += 1;
        }
        queue<int> q;
        for(int i = 0;i < n;i++)
        {
            if(ideg[i] == 1)
                q.push(i);
        }
        vector<int> ans;
        while(q.size())
        {
            int sz = q.size();
            vector<int> temp;
            while( sz--)
            {
                auto u = q.front();
                q.pop();
                temp.push_back(u);
                for(auto v : adj[u])
                {
                    if(ideg[v] > 0)
                    {
                        ideg[v] -- ;
                        if(ideg[v] == 1)
                            q.push(v);
                    }
                }
            }
            ans = temp;
        }
        if(ans.size() == 0)
            return {0};
        else
            return ans;
    }
};