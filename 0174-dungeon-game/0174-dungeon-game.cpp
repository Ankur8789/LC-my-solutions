class Solution {
public:
    int dp[201][201];
    int f(int i,int j,vector<vector<int>>& dun)
    {
        if(i<0 || j<0 || i>=dun.size() || j>=dun[0].size())
            return 1e9;
        if(i==dun.size()-1 && j==dun[0].size()-1)
        {
            if(dun[i][j]<=0)
                return 1-dun[i][j];
            else
                return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l=f(i+1,j,dun);
        int r=f(i,j+1,dun);
        int val=min(l,r);
        val-=dun[i][j];
        if(val<=0)
            return dp[i][j]= 1;
        else
            return dp[i][j]=val;
        
    }
    int calculateMinimumHP(vector<vector<int>>& dun) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,dun);
        return ans;
    }
};
