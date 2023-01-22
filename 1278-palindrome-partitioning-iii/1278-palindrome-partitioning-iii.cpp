class Solution {
public:
    typedef long long ll;
    int dp[101][101];
    ll p(string s)
    {
        ll n=s.length();
        ll cc=0;
        for(ll i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                cc++;        
        }
        return cc;
    }
    ll f(ll i,ll k,string s)
    {
        if(i==s.length())
        {
            if(k==0)
                return 0;
            else
                return INT_MAX-1;
        }
        if(k==0)
            return INT_MAX-1;
        if(dp[i][k]!=-1)
            return dp[i][k];
        ll ans=INT_MAX;
       for(ll idx=i;idx<s.length();idx++)
       {
            ll temp=p(s.substr(i,idx-i+1));
           ans=min(ans,temp+f(idx+1,k-1,s));
       }
        return dp[i][k]=ans;
        
    }
    int palindromePartition(string s, int k) 
    {
       memset(dp,-1,sizeof(dp));
        ll ans=f(0,k,s);
        return ans;
    }
};