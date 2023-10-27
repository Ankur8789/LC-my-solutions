class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int> ans;
        unordered_map<int,vector<int>> adj;
        vector<int> ideg(n);
        for(auto t: edges)
        {
            int u=t[0];
            int v=t[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            ideg[u]++;
            ideg[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ideg[i]==1)
                q.push(i);
        }
        while(q.size()>0)
        {
            int sz=q.size();
            vector<int> temp;
            while(sz--)
            {
                auto u=q.front();
                q.pop();
                temp.push_back(u);
                for(auto v: adj[u])
                {
                    if(ideg[v]>0)
                    {
                        ideg[v]--;
                        if(ideg[v]==1)
                            q.push(v);
                    }
                }
            }
            ans=temp;
        }
        if(ans.size()==0)
            ans.push_back(0);
        return ans;
        
    }
};