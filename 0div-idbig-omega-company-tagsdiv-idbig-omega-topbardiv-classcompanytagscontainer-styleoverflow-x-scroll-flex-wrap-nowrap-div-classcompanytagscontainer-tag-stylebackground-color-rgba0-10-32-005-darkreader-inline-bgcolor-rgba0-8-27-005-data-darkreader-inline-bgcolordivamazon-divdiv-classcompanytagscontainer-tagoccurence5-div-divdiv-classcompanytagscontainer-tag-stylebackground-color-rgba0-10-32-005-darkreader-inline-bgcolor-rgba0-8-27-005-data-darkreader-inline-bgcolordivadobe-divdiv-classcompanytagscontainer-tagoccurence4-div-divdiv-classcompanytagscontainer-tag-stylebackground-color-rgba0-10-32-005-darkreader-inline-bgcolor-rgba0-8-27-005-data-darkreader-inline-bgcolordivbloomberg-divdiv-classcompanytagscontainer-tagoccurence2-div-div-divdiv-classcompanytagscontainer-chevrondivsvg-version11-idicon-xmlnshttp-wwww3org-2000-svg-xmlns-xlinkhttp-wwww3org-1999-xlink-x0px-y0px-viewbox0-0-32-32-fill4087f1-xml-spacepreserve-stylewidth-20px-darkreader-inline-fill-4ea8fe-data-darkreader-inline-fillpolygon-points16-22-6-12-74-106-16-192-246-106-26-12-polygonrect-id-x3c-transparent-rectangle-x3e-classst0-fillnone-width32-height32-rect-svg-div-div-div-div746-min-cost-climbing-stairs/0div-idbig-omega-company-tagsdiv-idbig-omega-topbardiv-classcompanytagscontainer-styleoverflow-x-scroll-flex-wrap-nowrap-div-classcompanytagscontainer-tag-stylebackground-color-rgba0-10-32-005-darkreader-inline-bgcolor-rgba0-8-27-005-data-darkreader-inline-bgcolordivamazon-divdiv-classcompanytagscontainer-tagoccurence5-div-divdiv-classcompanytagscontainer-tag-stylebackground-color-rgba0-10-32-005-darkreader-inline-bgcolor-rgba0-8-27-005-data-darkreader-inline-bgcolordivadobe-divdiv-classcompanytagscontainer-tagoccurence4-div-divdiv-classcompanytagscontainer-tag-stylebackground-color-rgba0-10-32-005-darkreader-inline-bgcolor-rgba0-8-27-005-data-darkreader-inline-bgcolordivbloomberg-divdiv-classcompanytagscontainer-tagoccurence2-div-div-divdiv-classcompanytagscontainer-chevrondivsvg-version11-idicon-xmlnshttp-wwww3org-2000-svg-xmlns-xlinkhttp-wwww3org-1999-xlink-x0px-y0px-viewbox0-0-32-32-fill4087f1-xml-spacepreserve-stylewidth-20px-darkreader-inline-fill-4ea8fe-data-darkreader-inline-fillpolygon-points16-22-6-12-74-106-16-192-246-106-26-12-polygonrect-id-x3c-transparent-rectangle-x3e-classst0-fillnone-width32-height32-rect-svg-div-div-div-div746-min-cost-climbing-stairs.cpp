class Solution {
public:
    int t[1001];
    int f(int i,vector<int>& costs)
    {
        if(i>=costs.size())
            return 0;
        if(t[i]!=-1)
            return t[i];
        return t[i]=costs[i]+min(f(i+1,costs),f(i+2,costs));
    }
    int minCostClimbingStairs(vector<int>& costs)
    {  memset(t,-1,sizeof(t));
        int ans=min(f(0,costs),f(1,costs));
        return ans;
    }
};