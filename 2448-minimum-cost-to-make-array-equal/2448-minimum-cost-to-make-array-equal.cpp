class Solution {
public:
    typedef long long ll;
    const ll maxN=1e6+2;
    long long minCost(vector<int>& nums, vector<int>& cost)
    {
        ll ans=1e18;
        ll n=nums.size();
        vector<ll> v(maxN);
        for(ll i=0;i<n;i++)
            v[nums[i]]+=cost[i];
        vector<ll> pref(maxN),suff(maxN);
        ll ps=0;
        for(ll i=0;i<maxN;i++)
        {
            pref[i]+=ps;
            if(i-1>=0)
                pref[i]+=pref[i-1];
            ps+=v[i];
        }
        ps=0;
        for(ll i=maxN-1;i>=0;i--)
        {
            suff[i]+=ps;
            if(i+1<maxN)
                suff[i]+=suff[i+1];
            ps+=v[i];
        }
        for(ll i=1;i<maxN;i++)
            ans=min(ans,pref[i]+suff[i]);
        return ans;
        
        
    }
};