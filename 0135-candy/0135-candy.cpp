class Solution {
public:
    typedef long long ll;
    bool check(ll mid,ll val,vector<ll>& pref)
    {
        ll temp=mid-val;
        ll n=pref.size();
        temp/=n;
        for(auto t: pref)
        {
            if(temp+t<=0)
                return 0;
            // cout<<temp-t<<" ";
        }
        return 1;
    }
    int candy(vector<int>& rat) 
    {
        ll n=rat.size();
        vector<ll> pref(n,1),suff(n,1);
        for(ll i=1;i<n;i++)
        {
            if(rat[i]>rat[i-1])
                pref[i]=pref[i-1]+1;
        }
        for(ll i=n-2;i>=0;i--)
        {
            if(rat[i]>rat[i+1])
                suff[i]=suff[i+1]+1;
        }
        ll ans=0;
        for(ll i=0;i<n;i++)
        ans+=max(pref[i],suff[i]);
        return ans;
    }
};