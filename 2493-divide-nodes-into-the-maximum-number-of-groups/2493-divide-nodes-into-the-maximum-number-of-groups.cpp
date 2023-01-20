class Solution {
public:
    typedef long long ll;
    vector<ll> adj[501];
    ll grp[501];
    ll vis[501];
    ll col[501];
    //bi-partite
    bool bp(ll x,ll c)
    {
        vis[x]=1;
        col[x]=c;
        for(auto t: adj[x])
        {
            if(vis[t]==0)
            {
                if(!bp(t,c^1))
                    return false;
            }
            else
            {
                if(col[x]==col[t])
                    return false;
            }
        }
        return true;
    }
    
    //grouping
    void dfs(ll x,ll gp)
    {
        vis[x]=gp;
        for(auto t: adj[x])
        {
            if(vis[t]==0)
                dfs(t,gp);
        }
    }
    
    //sum
    ll f(vector<ll>& v)
    {  ll res=INT_MIN;
        for(ll i=0;i<v.size();i++)
        {
            queue<ll> q;
            q.push(v[i]);
            vector<ll> vis(501);
            vis[v[i]]=1;
            ll k=0;
            while(!q.empty())
            {
                ll sz=q.size();
                while(sz--)
                {
                    ll x=q.front();
                    q.pop();
                    for(auto t: adj[x])
                    {
                        if(vis[t]==0)
                        {
                            q.push(t);
                            vis[t]=1;
                        }
                    }
                }
                k++;
            }
            res=max(res,k);
            
        }
      return res;
    }
    
        
        
        
    int magnificentSets(int n, vector<vector<int>>& edges) 
    {
         for(auto t: edges)
         {
             adj[t[0]].push_back(t[1]);
             adj[t[1]].push_back(t[0]);
         }
         for(ll i=1;i<=n;i++)
         {
             if(vis[i]==0)
             {
                 bool ans=bp(i,0);
                 if(ans==false)
                     return -1;
             }
         }
         for(ll i=1;i<=n;i++)vis[i]=0;
        // grouping
        
        ll k=1;
        for(ll i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,k);
                k++;
            }
        }
        unordered_map<ll,vector<ll>> mp;
        for(ll i=1;i<=n;i++)
        {
            mp[vis[i]].push_back(i);
        }
        ll sum=0;
        for(auto t: mp)
        {
            vector<ll> a=t.second;
            sum+=f(a);
        }
        return sum;
        
    
    }
};