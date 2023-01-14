class Solution {
public:
    typedef long long ll;
    const ll mod=1e9+7;
    ll t[6][100001];
    ll f(ll pre,ll n)
    {
        if(n==0)
            return 1;
        if(t[pre][n]!=-1)
            return t[pre][n];
        if(pre==1)
        {
            return t[pre][n]=f(2,n-1)%mod;
        }
        else if(pre==2)
        {
            return t[pre][n]=(f(1,n-1)+f(3,n-1))%mod;
        }
        else if(pre==3)
        {
            return t[pre][n]=(f(1,n-1)+f(2,n-1)+f(4,n-1)+f(5,n-1))%mod;
        }
        else if(pre==4)
        {
            return t[pre][n]=(f(3,n-1)+f(5,n-1))%mod;                 
        }
        else
            return t[pre][n]=f(1,n-1)%mod;                     
    }
    int countVowelPermutation(int n) 
    {
        ll ans=0;
        memset(t,-1,sizeof(t));
        for(ll i=1;i<=5;i++)
        {
            ans=(ans+f(i,n-1))%mod;
        }
        return ans;
    }
};