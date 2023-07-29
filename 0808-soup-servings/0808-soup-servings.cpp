class Solution {
public:
    
    double f(int a,int b,vector<vector<double>>& dp)
    {
        if(a<=0 && b<=0)
            return 0.5;
        if(a<=0)
            return 1;
        if(b<=0)
            return 0;
        if(dp[a][b]!=-1)
            return dp[a][b];
        return dp[a][b]=(f(a-100,b,dp)+f(a-75,b-25,dp)+f(a-50,b-50,dp)+f(a-25,b-75,dp))/4;
    }
    double soupServings(int n) 
    {   
        if(n>4800)
            return 1;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        double ans=f(n,n,dp);
        return ans;
    }
};