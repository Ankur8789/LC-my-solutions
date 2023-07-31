class Solution {
public:
    int dp[9][1<<10][2][2];
    int f(int i,int msk,int tight,string& s,int taken)
    {
        if(i==s.size())
        {
            return 1;
        }
        if(dp[i][msk][tight][taken]!=-1)
            return dp[i][msk][tight][taken];
        int ans=0;
        if(taken==0)
        {
            int ub=9;
            if(tight)
                ub=s[i]-'0';
            for(int idx=0;idx<=ub;idx++)
            {
                if(idx==0)
                    ans+=f(i+1,msk,tight&(idx==ub),s,taken);
                else
                    ans+=f(i+1,msk|(1<<idx),tight&(idx==ub),s,taken^1);
            }
        }
        else
        {
            int ub=9;
            if(tight)
                ub=s[i]-'0';
            for(int idx=0;idx<=ub;idx++)
            {
                if((msk>>idx)&1)
                    continue;
                ans+=f(i+1,msk|(1<<idx),tight&(idx==ub),s,taken);
            }
        }
        return dp[i][msk][tight][taken]=ans;
        
    }
    int countNumbersWithUniqueDigits(int n) 
    {
        int val=1;
        for(int i=0;i<n;i++)
            val*=10;
        val--;
        string s=to_string(val);
        // cout<<s;
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,1,s,0);
        return ans;
    }
};