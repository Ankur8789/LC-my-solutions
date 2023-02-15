class Solution {
public:
    int dp[2001];
    int t[2001][2001];
    bool ipr(int i,int j,string& s)
    {
      if(i==j)
          return true;
      if(i==j-1)
          return s[i]==s[j];
        if(t[i][j]!=-1)
            return t[i][j];
        return t[i][j]=ipr(i+1,j-1,s) && (s[i]==s[j]);
    }
    int f(int i,string& s)
    {
        if(i==s.length())
            return -1;
        if(dp[i]!=-1)
            return dp[i];
        int ans=1e5;
        for(int idx=i;idx<s.length();idx++)
        {
            if(ipr(i,idx,s))
                ans=min(ans,1+f(idx+1,s));
        }
        return dp[i]=ans;
    }
    int minCut(string s) 
    {  memset(dp,-1,sizeof(dp));memset(t,-1,sizeof(t));
       int ans=f(0,s);
        return ans;
    }
};