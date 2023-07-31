class Solution {
public:
    int dp[1001][1001];
    int f(int i,int j,string& s1,string& s2)
    {
        if(i==s1.size() || j==s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=int(s1[i])+f(i+1,j+1,s1,s2);
        else
            return dp[i][j]=max(f(i+1,j,s1,s2),f(i,j+1,s1,s2));
    }
    int minimumDeleteSum(string s1, string s2) 
    {
        int sum=0;
        for(auto t: s1)
            sum+=int(t);
        for(auto t: s2)
            sum+=int(t);
        memset(dp,-1,sizeof(dp));
        return sum-2*f(0,0,s1,s2);
    }
};