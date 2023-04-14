class Solution {
public:
    int dp[1001][1001];
    int f(int i,int j,string& s1,string& s2)
    {
        if(i==s1.length() || j==s2.length())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]=1+f(i+1,j+1,s1,s2);
        else
            return dp[i][j]=max(f(i+1,j,s1,s2),f(i,j+1,s1,s2));
    }
    int longestPalindromeSubseq(string s) 
    {
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,s1,s2);
        return ans;
    }
};