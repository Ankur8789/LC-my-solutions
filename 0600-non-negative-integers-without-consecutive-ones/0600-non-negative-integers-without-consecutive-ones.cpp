class Solution {
public:
    int dp[32][2][2][11];
    int f(int i,int taken,int tight,int last,int n)
    {
        if(i<0)
            return 1;
        if(dp[i][taken][tight][last+1]!=-1)
            return dp[i][taken][tight][last+1];
        int ans=0;
        if(taken==0)
        {
           if((n>>i)&1)
           {
               int ub=1;
               if(tight)
                   ub=((n>>i)&1);
               for(int idx=0;idx<=ub;idx++)
               {
                   if(idx==0)
                       ans+=f(i-1,taken^1,(tight&(idx==ub)),idx,n);
                   else
                       ans+=f(i-1,taken^1,(tight&(idx==ub)),idx,n);
               }
           }
           else
               ans+=f(i-1,taken,tight,0,n);
        }
        else
        {
            int ub=1;
            if(tight)
                ub=((n>>i)&1);
            for(int idx=0;idx<=ub;idx++)
            {
                if(idx==1 && idx==last)
                    continue;
                ans+=f(i-1,taken,(tight&(idx==ub)),idx,n);
            }
        }
        return dp[i][taken][tight][last+1]=ans;
    }
    int findIntegers(int n) 
    {
       memset(dp,-1,sizeof(dp));
       string s=to_string(n);
       int ans=f(31,0,1,-1,n);
       return ans;
       
    }
};