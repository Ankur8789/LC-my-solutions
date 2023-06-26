class Solution {
public:
    int dp[11][2][2][1<<11][2];
    int f(int i,int tight,int taken,string& s,int msk,int dub)
    {
        if(i==s.size())
        {
            if(taken && dub)
                return 1;
            else
                return 0;
        }
        if(dp[i][tight][taken][msk][dub]!=-1)
            return dp[i][tight][taken][msk][dub];
        int limit=9;
        if(tight)
            limit=s[i]-'0';
        int ans=0;
        for(int idx=0;idx<=limit;idx++)
        {
            if(!taken)
            {
                if(idx==0)
                {
                   ans+=f(i+1,(tight & (idx==limit)),taken,s,msk,dub); 
                }
                else
                {
                    ans+=f(i+1,(tight & (idx==limit)),taken^1,s,msk|(1<<idx),dub);
                }
            }
            else
            {
               if((msk>>idx)&1)
               {
                  ans+=f(i+1,(tight & (idx==limit)),taken,s,msk,1);
               }
               else
               {
                   ans+=f(i+1,(tight & (idx==limit)),taken,s,msk|(1<<idx),dub);
               }
            }
        }
        return dp[i][tight][taken][msk][dub]=ans;
    }
    int numDupDigitsAtMostN(int n) 
    {
       memset(dp,-1,sizeof(dp));
       string s=to_string(n);
       int ans=f(0,1,0,s,0,0);
       return ans;
    }
};