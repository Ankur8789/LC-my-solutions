typedef long long ll;
ll mod=1e9+7;
class Solution {
public:
    ll dp[10001][8][8];
    ll f(ll x,ll n,ll prev,ll prev_pr)
    {
        if(x==n)
            return 1;
        if(dp[x][prev+1][prev_pr+1]!=-1)
            return dp[x][prev+1][prev_pr+1];
        ll ans=0;
        if(prev==1)
        {
           if(prev_pr!=2)
           {
               ans+=f(x+1,n,2,prev);
               ans%=mod;
           }
           if(prev_pr!=3)
           {
               ans+=f(x+1,n,3,prev);
               ans%=mod;
           }
           if(prev_pr!=4)
           {
              ans+=f(x+1,n,4,prev);
              ans%=mod;
           }
           if(prev_pr!=5)
           {
               ans+=f(x+1,n,5,prev);
               ans%=mod;
           }
           if(prev_pr!=6)
           {
               ans+=f(x+1,n,6,prev);
               ans%=mod;
           }
        }
        else if(prev==2)
        {
            if(prev_pr!=1)
            {
                ans+=f(x+1,n,1,prev);
                ans%=mod;
            }
            if(prev_pr!=3)
            {
                ans+=f(x+1,n,3,prev);
                ans%=mod;
            }
            if(prev_pr!=5)
            {
               ans+=f(x+1,n,5,prev);
               ans%=mod;
            }
        }
        else if(prev==3)
        {
            if(prev_pr!=2)
           {
               ans+=f(x+1,n,2,prev);
               ans%=mod;
           }
           if(prev_pr!=1)
           {
               ans+=f(x+1,n,1,prev);
               ans%=mod;
           }
           if(prev_pr!=4)
           {
              ans+=f(x+1,n,4,prev);
              ans%=mod;
           }
           if(prev_pr!=5)
           {
               ans+=f(x+1,n,5,prev);
               ans%=mod;
           }
        }
        else if(prev==4)
        {
            if(prev_pr!=1)
            {
                ans+=f(x+1,n,1,prev);
                ans%=mod;
            }
            if(prev_pr!=3)
            {
                ans+=f(x+1,n,3,prev);
                ans%=mod;
            }
            if(prev_pr!=5)
            {
               ans+=f(x+1,n,5,prev);
               ans%=mod;
            }
        }
        else if(prev==5)
        {
            if(prev_pr!=2)
           {
               ans+=f(x+1,n,2,prev);
               ans%=mod;
           }
           if(prev_pr!=3)
           {
               ans+=f(x+1,n,3,prev);
               ans%=mod;
           }
           if(prev_pr!=4)
           {
              ans+=f(x+1,n,4,prev);
              ans%=mod;
           }
           if(prev_pr!=6)
           {
               ans+=f(x+1,n,6,prev);
               ans%=mod;
           }
           if(prev_pr!=1)
           {
               ans+=f(x+1,n,1,prev);
               ans%=mod;
           }
        }
        else
        {
            if(prev_pr!=1)
            {
                ans+=f(x+1,n,1,prev);
                ans%=mod;
            }
            
            if(prev_pr!=5)
            {
               ans+=f(x+1,n,5,prev);
               ans%=mod;
            }
        }
        return dp[x][prev+1][prev_pr+1]=ans;
        
    }
    int distinctSequences(int n) 
    {  ll ans=0;
      memset(dp,-1,sizeof(dp));
       for(ll i=1;i<=6;i++)
       {
           ans+=f(1,n,i,-1);
           ans%=mod;
       }
     return ans;
    }
};