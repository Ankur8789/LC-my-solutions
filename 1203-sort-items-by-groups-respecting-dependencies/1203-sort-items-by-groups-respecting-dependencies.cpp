class Solution {
public:
    typedef long long ll;
    vector<ll> adj1[100001];
    ll ideg1[100001];
    vector<ll> adj2[100001];
    ll ideg2[100001];
    vector<int> sortItems(int n, int m, vector<int>& grp, vector<vector<int>>& bi) 
    {
       vector<int> ans;
        
        for(ll i=0;i<grp.size();i++)
        {
            if(grp[i]==-1)
            {
                grp[i]=m;
                m++;
            }
        }
        for(ll i=0;i<bi.size();i++)
        {
            for(ll j=0;j<bi[i].size();j++)
            {
                adj1[bi[i][j]].push_back(i);
                ideg1[i]++;
            }
        }
        // item wise toposort
        vector<ll> temp;
        queue<ll> q1;
        for(ll i=0;i<n;i++)
        {
            if(ideg1[i]==0)
                q1.push(i);
        }
        while(q1.size()>0)
        {
            ll x=q1.front();
            temp.push_back(x);
            q1.pop();
            for(auto t: adj1[x])
            {
                ideg1[t]--;
                if(ideg1[t]==0)
                    q1.push(t);
            }
        }
       
        
        vector<ll> hex;
        queue<ll> q2;
        //group wise toposort
        for(ll i=0;i<bi.size();i++)
        {
            for(ll j=0;j<bi[i].size();j++)
            {   
                if(grp[i]==grp[bi[i][j]])
                    continue;
                adj2[grp[bi[i][j]]].push_back(grp[i]);
                ideg2[grp[i]]++;
            }
        }
        for(ll i=0;i<m;i++)
        {
            if(ideg2[i]==0)
                q2.push(i);
        }
        
        while(q2.size()>0)
        {
            ll x=q2.front();
            q2.pop();
            hex.push_back(x);
            for(auto t: adj2[x])
            {
                ideg2[t]--;
                if(ideg2[t]==0)
                    q2.push(t);
            }
            
            
        }
       
        map<ll,vector<ll>> mp;
        for(ll i=0;i<temp.size();i++)
            mp[grp[temp[i]]].push_back(temp[i]);
        for(ll i=0;i<hex.size();i++)
        {
            for(ll j=0;j<mp[hex[i]].size();j++)
                ans.push_back(mp[hex[i]][j]);
        }
        for(auto t: temp)cout<<t<<" ";
        cout<<endl;
        for(auto t: hex)cout<<t<<" ";
        cout<<endl;
        for(auto t: ans)cout<<t<<" ";
        if(ans.size()!=n)
            return {};
        return ans;
        
        
        
        
        
    }
};