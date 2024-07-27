class Solution {
public:
    typedef long long ll;
    unordered_map<char,vector<pair<int,char>>> adj;
    vector<ll> dfs(char u)
    {
        multiset<pair<ll,char>> ms;
        ms.insert({0,u});
        vector<ll> dis(26,1e9);
        dis[u-'a']=0;
        while(ms.size())
        {
            auto x=*ms.begin();
            ms.erase(ms.begin());
            ll d=x.first;
            char u=x.second;
            for(auto t: adj[u])
            {
                ll ct=t.first;
                char v=t.second;
                if(dis[v-'a']>d+ct)
                {
                    if(ms.count({dis[v-'a'],v}))
                        ms.erase({dis[v-'a'],v});
                    dis[v-'a']=d+ct;
                    ms.insert({dis[v-'a'],v});
                }
            }
        }
        return dis;
    }
    long long minimumCost(string source, string target, vector<char>& org, vector<char>& chg, vector<int>& cost)
    {
       ll ans=0;
       ll n=source.size();
       
       ll m=org.size();
       for(ll i=0;i<m;i++)
       {
           char u=org[i];
           char v=chg[i];
           ll ct=cost[i];
           adj[u].push_back({ct,v});
       }
        vector<vector<ll>> res;
        for(char ch='a';ch<='z';ch++)
            res.push_back(dfs(ch));
       for(ll i=0;i<n;i++)
       {
           if(source[i]==target[i])
               continue;
           char u=source[i];
           char v=target[i];
           vector<ll> tem=res[u-'a'];
           if(tem[v-'a']==1e9)
               return -1;
           ans+=tem[v-'a'];
           
       }
        return ans;
    }
};