class Solution {
public:
    int dp[32][2][2][3];
    int f(int idx,int first,int tight,int n,int last)
    {
        if(idx<0)
            return 1;
        if(dp[idx][first][tight][last+1]!=-1)
            return dp[idx][first][tight][last+1];
        int ans=0;
        if(first)
        {
           int ub=1;
           if(tight)
               ub=((n>>idx)&1);
           for(int i=0;i<=ub;i++)
           {
               if(i==1  && i==last)
                   continue;
               ans+=f(idx-1,first,(tight & (i==ub)),n,i);
           }
        }
        else
        {
            if((n>>idx)&1)
            {
                int ub=((n>>idx)&1);
                for(int i=0;i<=ub;i++)
                {
                    if(i==1 && i==last)
                        continue;
                    ans+=f(idx-1,first^1,(tight & (i==ub)),n,i);
                }
            }
            else
            {
                ans+=f(idx-1,first,tight,n,0);
            }
        }
        return dp[idx][first][tight][last+1]=ans;
        
    }
    int findIntegers(int n) 
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(31,0,1,n,-1);
       return ans;
    }
};