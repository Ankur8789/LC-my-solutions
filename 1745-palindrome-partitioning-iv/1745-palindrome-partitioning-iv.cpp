class Solution {
public:
    int dp[2001][4];
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
    
    
    bool f(int i,string& s,int k)
    {
        if(i>=s.length())
        {
            if(k==0)
                return true;
            else
                return false;
        }
        if(k==1)
        {
            if(ipr(i,s.length()-1,s))
                return true;
            else
                return false;
        }
        
        if(dp[i][k]!=-1)
            return dp[i][k];
        for(int idx=i;idx<s.length();idx++)
        {
            if(ipr(i,idx,s))
            {
                 bool x=f(idx+1,s,k-1);
                if(x)
                    return dp[i][k]=true;
            }
            
        }
        return dp[i][k]=false;
    }
    bool checkPartitioning(string s) 
    {
         memset(dp,-1,sizeof(dp));
         memset(t,-1,sizeof(t));

        bool ans=f(0,s,3);
        if(ans)
            return true;
        else
            return false;
    }
};