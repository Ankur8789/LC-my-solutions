class Solution {
public:
    typedef long long ll;
    ll dp[101][101][101];
    ll f(ll i,ll j1,ll j2,vector<vector<int>>& grid)
    {
        if(j1<0 || j2<0 || j1>=grid[0].size() || j2>=grid[0].size())
            return -1e18;
        if(i==grid.size())
            return 0;
        auto& X=dp[i][j1][j2];
        if(X!=-1)
            return X;
        ll ans=-1e18;
        for(ll x=-1;x<2;x++)
        {
            for(ll y=-1;y<2;y++)
            {
                ll nj1=j1+x;
                ll nj2=j2+y;
                if(j1==j2)
                    ans=max(ans,grid[i][j1]+f(i+1,nj1,nj2,grid));
                else
                    ans=max(ans,grid[i][j1]+grid[i][j2]+f(i+1,nj1,nj2,grid));     
            }
        }
        return X=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        ll ans=f(0,0,grid[0].size()-1,grid);
        return ans;
    }
};