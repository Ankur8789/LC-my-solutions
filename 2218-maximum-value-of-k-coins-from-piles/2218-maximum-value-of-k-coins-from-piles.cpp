class Solution {
public:
    int dp[2001][2001];
    int f(int i,int k,vector<vector<int>>& piles)
    {  
        if(k<0)
            return -1e9;
        if(k==0)
            return 0;
        if(i==piles.size())
            return -1e9;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=-1e5;
        ans=max(ans,f(i+1,k,piles));
        int sum=0;
        for(int idx=0;idx<piles[i].size();idx++)
        {  
            sum+=piles[i][idx];
            ans=max(ans,sum+f(i+1,k-idx-1,piles));
        }
        return dp[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,k,piles);
        return ans;
    }
};