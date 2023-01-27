class Solution {
public:
    //0/1 bfs
    typedef long long ll;
    vector<pair<ll,ll>> adj[100001];
    ll vis[100001];
    int minReorder(int n, vector<vector<int>>& cnc)
    {
        for(auto t: cnc)
        {
            adj[t[0]].push_back({t[1],0});
            adj[t[1]].push_back({t[0],1});
        }
        ll cc=0;
        vis[0]=1;
        queue<ll> q;
        q.push(0);
        while(q.size()>0)
        {
            ll x=q.front();
            q.pop();
            for(auto t: adj[x])
            {  //cout<<x<<"->"<<t.first<<endl;
                if(vis[t.first]==1)
                    continue;
                if(t.second==0)
                    cc++;
                q.push(t.first);
                vis[t.first]=1;
            }
        }
        return cc;
        
    }
};