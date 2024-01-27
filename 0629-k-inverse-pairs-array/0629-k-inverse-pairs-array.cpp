class Solution {
public:
    const int mod=1e9+7;
    int dp[1001][1001];
    int f(int i,int n,int k)
    {
        if(k<0)
            return 0;
        if(k==0)
            return 1;
        if(i==n)
            return  0;
        auto& x=dp[i][k];
        if(x!=-1)
            return x;
        int ans=0;
        for(int idx=i;idx>=0;idx--)
        {
            //  new pairs=i-idx;
            if(i-idx>k)
                break;
            ans+=f(i+1,n,k-(i-idx));
            ans%=mod;
        }
        return x=ans;
    }
    int kInversePairs(int n, int k)
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,n,k);
        return ans;
    }
};