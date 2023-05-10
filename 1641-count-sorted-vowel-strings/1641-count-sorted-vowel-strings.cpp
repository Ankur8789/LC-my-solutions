class Solution {
public:
    int dp[51][6];
    int f(int i,int mx,int n)
    {
        if(i==n)
            return 1;
        if(dp[i][mx]!=-1)
            return dp[i][mx];
        int ans=0;
        for(int idx=1;idx<=5;idx++)
        {
            if(idx>=mx)
            {
                ans+=f(i+1,idx,n);
            }
        }
        return dp[i][mx]=ans;
    }
    int countVowelStrings(int n) 
    {
        memset(dp,-1,sizeof(dp));
       int ans=f(0,0,n);
       return ans;
    }
};