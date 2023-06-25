class Solution {
public:
    int dp[11][2][2000][2];
    int f(int i,int tight,string&s,int msk,int taken)
    {
        if(i==s.size())
        {
            if(taken)
                return 1;
            else
                return 0;
        }
        if(dp[i][tight][msk][taken]!=-1)
            return dp[i][tight][msk][taken];
        int ans=0;
        int limit=9;
        if(tight)
            limit=s[i]-'0';
        for(int idx=0;idx<=limit;idx++)
        {
            if(!taken)
            {
               if(idx==0)
               {
                  ans+=f(i+1,(tight & (idx==limit)),s,msk,taken);
               }
               else
               {
                   if(!((msk>>idx)&1))
                   {
                       ans+=f(i+1,(tight & (idx==limit)),s,msk|(1<<idx),1);
                   }
               }
            }
            else
            {
                if(!((msk>>idx)&1))
                    ans+=f(i+1,(tight & (idx==limit)),s,msk|(1<<idx),taken);
            }
        }
        return dp[i][tight][msk][taken]=ans;
    }
    int countSpecialNumbers(int n) 
    {
       memset(dp,-1,sizeof(dp));
       string s=to_string(n);
       int ans=f(0,1,s,0,0);
       return ans;
    }
};