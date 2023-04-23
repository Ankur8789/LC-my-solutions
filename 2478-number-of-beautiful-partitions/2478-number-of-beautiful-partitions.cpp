class Solution {
public:
    const int mod=1e9+7;
    int dp[1001][1001];
    bool check(char ch)
    {
        if(ch=='2' || ch=='3' || ch=='5' || ch=='7')
            return true;
        return false;
    }
    int f(int i,string & s,int k,int mn)
    {
        if(i==s.size() && k==0)
            return 1;
        if(k==0 || i==s.size())
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=0;
        if(!check(s[i]))
            return 0;
        int st=s[i];
        for(int idx=i;idx<s.size();idx++)
        {
            if(idx-i+1<mn)
                continue;
            else
            {
                if(!check(s[idx]))
                {
                    ans+=f(idx+1,s,k-1,mn);
                    ans%=mod;
                }
            }
        }
        return dp[i][k]=ans;
    }
    int beautifulPartitions(string s, int k, int mn) 
    {
        memset(dp,-1,sizeof(dp));
       int ans=f(0,s,k,mn);
       return ans;
    }
};