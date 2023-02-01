class Solution {
public:
    //sonetimes thge use of map will be more efficient as you dont have to store all of it
    typedef long long ll;
    unordered_map<ll,ll> mp;
    ll f(ll n)
    {
        if(n==1)
            return 0;
        if(n<1)
            return INT_MAX-1;
        if(mp.find(n)!=mp.end())
            return mp[n];
        if(n%2==0)
            return mp[n]=1+f(n/2);
        else
            return mp[n]=min(1+f(n-1),1+f(n+1));
    }
    int integerReplacement(int n) 
    {
        ll ans=f(n);
        return ans;
    }
};