class Solution {
public:
    typedef long long ll;
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vector<ll> fre(n);
        for(auto t: roads)
        {
            fre[t[0]]++;
            fre[t[1]]++;
        }
        vector<pair<ll,ll>> vp;
        for(ll i=0;i<n;i++)
            vp.push_back({fre[i],i});
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        unordered_map<ll,ll> val;
        ll x=n;
        for(auto t: vp)
        {
            val[t.second]=x--;
        }
        ll sum=0;
        for(auto t: roads)
            sum+=val[t[0]]+val[t[1]];
        return sum;
            
    }
};