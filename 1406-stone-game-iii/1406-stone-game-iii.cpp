class Solution {
public:
    int dp[50001][2];
    int f(int i,int turn,vector<int>& sv)
    {
        if(i>=sv.size())
            return 0;
        if(dp[i][turn]!=-1)
            return dp[i][turn];
        if(turn)
        {
            int ans=-1e5;
            int ps=0;
            for(int idx=i;idx<i+3;idx++)
            {
                if(idx==sv.size())
                    break;
                ps+=sv[idx];
                ans=max(ans,ps+f(idx+1,turn^1,sv));
            }
            return dp[i][turn]=ans;
        }
        else
        {
            int ans=1e9;
            for(int idx=i;idx<i+3;idx++)
            {
                if(idx==sv.size())
                    break;
                ans=min(ans,f(idx+1,turn^1,sv));
            }
            return dp[i][turn]=ans;
        }
    }
    string stoneGameIII(vector<int>& sv)
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,sv);
        int sum=0;
        for(auto t:sv)
            sum+=t;
        if(sum-ans<ans)
            return "Alice";
        else if(sum-ans==ans)
            return "Tie";
        else
            return "Bob";
    }
};