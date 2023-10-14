class Solution {
public:
    typedef long long ll;
    ll dp[501][1002];
    ll f(int i,int currtime,vector<int>& time,vector<int>& cost)
    {
        if(i==time.size())
        {
            if(currtime>=0)
                return 0;
            else
                return 1e12;
        }
        if(dp[i][currtime+500]!=-1)
            return dp[i][currtime+500];
        ll ans=1e12;
        ans=min({ans,f(i+1,currtime-1,time,cost),cost[i]+f(i+1,min(currtime+time[i],500),time,cost)});
        return dp[i][currtime+500]=ans;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) 
    {
        memset(dp,-1,sizeof(dp));
        ll ans=f(0,0,time,cost);
        return ans;
    }
};