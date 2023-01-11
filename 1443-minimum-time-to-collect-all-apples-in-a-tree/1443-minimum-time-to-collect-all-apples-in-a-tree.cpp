class Solution {
public:
    int vis[100001];
    vector<int> adj[100001];
    int f(int x,vector<bool>& ap)
    {
        vis[x]=1;
        int t=0,ct;
        for(auto y: adj[x])
        {
            if(vis[y]==0)
            {
                ct=f(y,ap);
                if(ct!=0 || ap[y]==true)
                    t+=(ct+2);
            }
        }
        return t;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& ap) 
    {
        for(auto t: edges)
        {
             adj[t[0]].push_back(t[1]);
             adj[t[1]].push_back(t[0]);
        }
        int ans=f(0,ap);
        return ans;
    }
};