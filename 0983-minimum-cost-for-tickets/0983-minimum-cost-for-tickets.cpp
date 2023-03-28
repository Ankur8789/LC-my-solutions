class Solution {
public:
    int f(int i,vector<int> &dp,vector<int> &days,vector<int> &costs)
    {
        if(i>=days.size())
        {
            return dp[i]=0;
        }
        if(dp[i]!=-1)
            return dp[i];
        int day1=upper_bound(days.begin(),days.end(),days[i]+1-1)-days.begin();
        int x=costs[0]+f(day1,dp,days,costs);
        int day7=upper_bound(days.begin(),days.end(),days[i]+7-1)-days.begin();
        int y=costs[1]+f(day7,dp,days,costs);
        int day30=upper_bound(days.begin(),days.end(),days[i]+30-1)-days.begin();
        int z=costs[2]+f(day30,dp,days,costs);

        return dp[i]=min({x,y,z});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n=days.size(),m=costs.size();
        vector<int> dp(n+1,-1);
        return f(0,dp,days,costs);
    }
};
