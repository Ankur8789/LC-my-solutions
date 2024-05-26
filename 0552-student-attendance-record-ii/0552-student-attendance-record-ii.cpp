class Solution {
public:
    const int mod=1e9+7;
    int dp[100001][5][5];
    int f(int i,int absent,int late,int n)
    {
        if(i==n)
            return 1;
        auto& x=dp[i][absent][late];
        if(x!=-1)
            return x;
        int ans=0;
        if(absent<1)
            ans+=f(i+1,absent+1,0,n),ans%=mod;
        if(late==0 || late==1)
            ans+=f(i+1,absent,late+1,n),ans%=mod;
        ans+=f(i+1,absent,0,n);
        ans%=mod;
        return x=ans;
    }
    int checkRecord(int n) 
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(0,0,0,n);
       return ans;
    }
};