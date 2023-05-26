class Solution {
public:
    int dp[101][2][101];
    int f(int i,int turn,vector<int>& piles,int m)
    {
        if(i>=piles.size())
            return 0;
        if(dp[i][turn][m]!=-1)
            return dp[i][turn][m];
            
        if(turn)
        {
            int ps=0;
            int val=0;
            int ans=0;
            for(int idx=i;idx<i+2*m;idx++)
            {
                if(idx==piles.size())
                    break;
                ps+=piles[idx];
                val++;
                ans=max(ans,ps+f(idx+1,turn^1,piles,max(val,m)));
            }
            return dp[i][turn][m]= ans;
        }
        else
        {
            int ans=INT_MAX;
            int val=0;
            for(int idx=i;idx<i+2*m;idx++)
            {
                if(idx==piles.size())
                    break;
                val++;
                ans=min(ans,f(idx+1,turn^1,piles,max(val,m)));
            }
             return dp[i][turn][m]=ans;
        }
       
    }
    int stoneGameII(vector<int>& piles) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,piles,1);
        return ans;
    }
};