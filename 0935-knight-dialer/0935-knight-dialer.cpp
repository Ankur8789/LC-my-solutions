class Solution {
public:
    typedef long long ll;
    const int mod=1e9+7;
    ll t[11][11][5001];
    bool check(ll i,ll j)
    {
        if(i<0 || j<0)
            return false;
        if(i>3 || j>2)
            return false;
        if(i==3 && j==0)
            return false;
        if(i==3 && j==2)
            return false;
        return true;
    }
    ll f(ll i,ll j,ll n)
    {
        if(n==0)
            return 1;
         if(t[i][j][n]!=-1)
             return t[i][j][n];
        ll ans=0;
         if(check(i+2,j+1))
             ans=(ans+f(i+2,j+1,n-1))%mod;
        if(check(i+1,j+2))
             ans=(ans+f(i+1,j+2,n-1))%mod;
        if(check(i+2,j-1))
             ans=(ans+f(i+2,j-1,n-1))%mod;
        if(check(i+1,j-2))
             ans=(ans+f(i+1,j-2,n-1))%mod;
        if(check(i-1,j+2))
            ans=(ans+f(i-1,j+2,n-1))%mod;
        if(check(i-2,j+1))
             ans=(ans+f(i-2,j+1,n-1))%mod;
        if(check(i-1,j-2))
            ans=(ans+f(i-1,j-2,n-1))%mod;
        if(check(i-2,j-1))
            ans=(ans+f(i-2,j-1,n-1))%mod;
        return t[i][j][n]=ans;
    }
    int knightDialer(int n)
    {   memset(t,-1,sizeof(t));
        ll ans=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
               if(check(i,j))
                   ans=(ans+f(i,j,n-1))%mod;
            }
        }
        return ans;
    }
};