class Solution {
public:
    int dp[1001][1001];
    int f(int i,int j,string& s1,string& s2)
    {
        if(i==s1.size() || j==s2.size())
            return 0;
        auto& x=dp[i][j];
        if(x!=-1)
            return x;
        int ans=0;
        if(s1[i]==s2[j])
            ans=max({ans,1+f(i+1,j+1,s1,s2),f(i+1,j,s1,s2),f(i,j+1,s1,s2),f(i+1,j+1,s1,s2)});
        else
            ans=max({ans,f(i+1,j,s1,s2),f(i,j+1,s1,s2),f(i+1,j+1,s1,s2)});
        return x=ans;
    }
    int longestCommonSubsequence(string text1, string text2)
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(0,0,text1,text2);
       return ans;
    }
};