class Solution {
public:
    int fin;
    int dp[1001][1001];
    int f(int n,int curr){
        if(n<0)
            return 1e9;
        if(n==0)
            return 0;
        auto& x=dp[n][curr];
        if(x!=-1)
            return x;
        int ans=1e9;
        if(curr){
            ans=min(ans,1+f(n-curr,curr));
            ans=min(ans,1+f(n-curr,0));
        }else{
            ans=min(ans,1+f(n,fin-n));
        }
        return x=ans;
    }
    int minSteps(int n) {
       fin=n;
       memset(dp,-1,sizeof(dp));
       int ans=f(n-1,0);
       return ans;
    }
};