class Solution {
public:
    int dp[10][2][1<<11][2][2];
    int f(int i,int tight,int msk,int taken,string& s,int rep)
    {
        if(i==s.size())
        {
            if(taken)
                return 1;
            else
                return 0;
        }
        if(dp[i][tight][msk][taken][rep]!=-1)
            return dp[i][tight][msk][taken][rep];
        int ub=9;
        if(tight)
            ub=s[i]-'0';
        int ans=0;
        for(int idx=0;idx<=ub;idx++)
        {
            if(rep==0)
            {
                if(idx==0)
                    ans+=f(i+1,tight&(idx==ub),msk,taken,s,rep);
                else
                    ans+=f(i+1,tight&(idx==ub),msk|(1<<idx),taken,s, rep^1);
            }
            else
            {
                if((msk>>idx)&1)
                    ans+=f(i+1,tight&(idx==ub),msk,1,s,rep);
                else
                    ans+=f(i+1,tight&(idx==ub),msk|(1<<idx),taken,s,rep);
            }
        }
        return dp[i][tight][msk][taken][rep]=ans;
    }
    int numDupDigitsAtMostN(int n) 
    {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        int ans=f(0,1,0,0,s,0);
        return ans;
    }
};