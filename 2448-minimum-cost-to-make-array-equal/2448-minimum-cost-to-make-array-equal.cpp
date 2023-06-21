class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& nums, vector<int>& cost)
    {
        ll ans=1e18;
        ll n=nums.size();
        vector<ll> pref(n),suff(n),prefc(n),suffc(n);
        ll ps=0;
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++)
            v.push_back({nums[i],cost[i]});
        sort(v.begin(),v.end());
        ll res=1e18;
        vector<ll> lsum(n), rsum(n);
        lsum[0] = 0;
        rsum[n-1] = 0;
        ll l = v[0].second, r = v[n-1].second;
        
        for(ll i=1; i<n; i++)
        {
            lsum[i] = lsum[i-1] + (v[i].first - v[i-1].first)*l;
            l += v[i].second;
            
            rsum[n-i-1] = rsum[n-i] + (v[n-i].first - v[n-i-1].first)*r;
            r += v[n-i-1].second;          
        }
        
        for(ll i=0; i<n; i++)
        {
            ans = min(lsum[i] + rsum[i], ans);
        }
        
        return ans;
        
    }
};