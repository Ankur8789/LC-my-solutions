class Solution {
public:
    typedef long long ll;
    vector<pair<ll,ll>> adj[101];
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) 
    {  vector<vector<ll>> dis(n,vector<ll>(2,1e5));
        for(ll i=0;i<re.size();i++)
            adj[re[i][0]].push_back({re[i][1],0});
        for(ll i=0;i<be.size();i++)
            adj[be[i][0]].push_back({be[i][1],1});
        queue<pair<ll,ll>> q;
        dis[0][0]=0;
        dis[0][1]=0;
        q.push({0,0});
        q.push({0,1});
        while(q.size()>0)
        {
            pair<ll,ll> p=q.front();
            q.pop();
            ll node=p.first;
            ll col=p.second;
            for(auto t: adj[node])
            {
                ll newnode=t.first;
                ll newcol=t.second;
                if(dis[newnode][newcol]>dis[node][col]+1 && newcol!=col)
                {
                    dis[newnode][newcol]=dis[node][col]+1;
                    q.push(t);
                }
            }
        }
        vector<int> ans(n);
        for(ll i=0;i<n;i++)
        {
            ll mn=min(dis[i][0],dis[i][1]);
            if(mn==1e5)
                ans[i]=-1;
            else
                ans[i]=mn;
            
        }
        return ans;
        
    }
};