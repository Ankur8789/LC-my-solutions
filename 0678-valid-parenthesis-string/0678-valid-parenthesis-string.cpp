class Solution {
public:
    int dp[101][101];
    bool f(int i,int tot,string& s)
    {
        if(tot<0)
            return 0;
        if(i==s.size())
        {
            if(tot==0)
                return 1;
            else
                return 0;
        }
        if(dp[i][tot]!=-1)
            return dp[i][tot];
        bool ans=false;
        if(s[i]=='*')
        {
           ans|=f(i+1,tot+1,s);
           if(ans)
               return dp[i][tot]=true;
           ans|=f(i+1,tot-1,s);
           if(ans)
               return dp[i][tot]=true;
            ans|=f(i+1,tot,s);
            if(ans)
               return dp[i][tot]=true;
        }
        else
        {
            if(s[i]==')')
            {
                ans|=f(i+1,tot-1,s);
                if(ans)
                    return dp[i][tot]=true;
            }
            else
            {
                ans|=f(i+1,tot+1,s);
                if(ans)
                    return dp[i][tot]=true;
            }
        }
        return dp[i][tot]=false;
    }
    bool checkValidString(string s) 
    {
        memset(dp,-1,sizeof(dp));
        bool ans=f(0,0,s);
        return ans;
    }
};