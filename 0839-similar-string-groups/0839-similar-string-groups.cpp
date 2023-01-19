class Solution {
public:
    typedef long long ll;
    vector<ll> adj[100001];
    ll vis[100001];
    void dfs(ll x)
    {
        vis[x]=1;
        for(auto t: adj[x])
        {
            if(vis[t]==0)
                dfs(t);
        }
    }
    int numSimilarGroups(vector<string>& strs) 
    {
        unordered_map<string,ll> mp;
       // unordered_set<string> st;
       // sort(strs.begin(),strs.end());
        
        ll p=1;
        ll cc=0;
        for(ll i=0;i<strs.size();i++)
        {
            for(ll j=i+1;j<strs.size();j++)
            {
                string s1=strs[i];
                string s2=strs[j];
                if(mp.find(s1)==mp.end())
                mp[s1]=p++;
                if(mp.find(s2)==mp.end())
                mp[s2]=p++;
                ll tmp=0;
                for(ll k=0;k<s1.length();k++)
                {
                    if(s1[k]!=s2[k])
                        ++tmp;
                }
                if(tmp==0 || tmp==2)
                {
                    
                    adj[mp[s1]].push_back(mp[s2]);
                    adj[mp[s2]].push_back(mp[s1]);
                }
            }
        }
        for(auto t: mp)
            cout<<t.first<<endl;
        cout<<mp.size()<<endl;
        for(ll i=1;i<=mp.size();i++)
        {
            if(vis[i]==0)
            {
              dfs(i);
                cc++;
            }
        }
        return cc;
    }
};