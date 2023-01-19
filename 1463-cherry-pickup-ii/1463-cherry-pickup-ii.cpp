class Solution {
public:
    //double decker dp...first time this type of question????????
    typedef long long ll;
    ll dp[101][101][101];
    ll f(ll i,ll j1,ll j2,vector<vector<int>>& grid)
    {
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
            return 1LL*INT_MIN-1;
        if(i==grid.size()-1)
        {
            if(j1==j2)
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        ll ans=0;
        for(ll x=-1;x<=1;x++)
        {
            for(ll y=-1;y<=1;y++)
            {
                if(j1==j2)
                    ans=max(ans,grid[i][j1]+f(i+1,j1+x,j2+y,grid));
                else
                    ans=max(ans,grid[i][j1]+grid[i][j2]+f(i+1,j1+x,j2+y,grid));
            }
        }
        return dp[i][j1][j2]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid)
    { 
        memset(dp,-1,sizeof(dp));
        ll ans=f(0,0,grid[0].size()-1,grid);
        return ans;
    }
};