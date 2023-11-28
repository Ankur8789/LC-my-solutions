class Solution {
public:
    const int mod=1e9+7;
    int dp[100001][5];
    int f(int i,int seat,string& s)
    {
        if(i==s.size())
            return (seat==2);
        if(dp[i][seat]!=-1)
            return dp[i][seat];
        int ans=0;
        if(s[i]=='P')
        {
           if(seat==2)
           {
             ans+=f(i+1,0,s);
             ans%=mod;
             ans+=f(i+1,seat,s);
             ans%=mod;
           }
           else if(seat==1)
           {
              ans+=f(i+1,seat,s);
              ans%=mod;
           }
           else
           {
              ans+=f(i+1,seat,s);
              ans%=mod;
           }
        }
        else
        {
            if(seat==2)
            {
               ans+=0;
               ans%=mod;
            }
            else if(seat==1)
            {
               ans+=f(i+1,seat+1,s);
               ans%=mod;
               ans+=f(i+1,0,s);
               ans%=mod;
            }
            else
            {
               ans+=f(i+1,seat+1,s);
               ans%=mod;
            }
        }
        return dp[i][seat]=ans;
    }
    int numberOfWays(string s) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,s);
        return ans;
    }
};