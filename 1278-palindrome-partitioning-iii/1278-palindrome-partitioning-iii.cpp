#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
typedef long long ll;
class Solution {
public:
    ll dp[101][101];
    ll t(string s)
    {
        ll cc=0;
        ll n=s.length();
        for(ll i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                ++cc;
        }    
        return cc;
        
    }
    ll f(ll i,ll k,string s)
    {
        if(i>=s.length())
        {
            if(k==0)
                return 0;
            else
                return 1e5;
        }
        if(k==0)
            return 1e5;
        if(dp[i][k]!=-1)
            return dp[i][k];
        ll ans=1e5;
        for(ll idx=i;idx<s.length();idx++)
        {
            ll x=t(s.substr(i,idx-i+1));
            ans=min(ans,x+f(idx+1,k-1,s));
        }
        return  dp[i][k]=ans;
    }
    int palindromePartition(string s, int k) 
    {
        fastio();
        memset(dp,-1,sizeof(dp));
        ll ans=f(0,k,s);
        return ans;
    }
};