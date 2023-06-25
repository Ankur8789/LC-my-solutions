class Solution {
public:
    const int mod=1e9+7;
    int dp[101][201];
    int f(int i,int fin,int fuel,vector<int>& loc)
    {
        if(dp[i][fuel]!=-1)
            return dp[i][fuel];
        int ans=0;
        if(i==fin)
            ans++;
        for(int idx=0;idx<loc.size();idx++)
        {
            if(idx==i)
                continue;
            if(abs(loc[i]-loc[idx])<=fuel)
            {
                ans+=f(idx,fin,fuel-abs(loc[i]-loc[idx]),loc);;
                ans%=mod;
            }
        }
        return dp[i][fuel]=ans;
    }
    int countRoutes(vector<int>& loc, int st, int fin, int fuel) 
    {
       memset(dp,-1,sizeof(dp));
       int ans=0;
       for(int i=0;i<loc.size();i++)
       {
           if(i==st)
           {
               ans=f(i,fin,fuel,loc);
               break;
           }
       }
       return ans;
    }
};