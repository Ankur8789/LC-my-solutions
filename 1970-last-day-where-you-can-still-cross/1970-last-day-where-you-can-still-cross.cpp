class Solution {
public:
    typedef long long ll;
    // int dx[4]={0,0,1,-1};
    // int dy[4]={1,-1,0,0};
    // bool f(ll x,ll y,ll r,ll c,vector<vector<ll>>& v,vector<vector<ll>>& vis)
    // {
    //     if(x<0 || y<0 || x>=r || y>=r)
    //         return false;
    //     if(vis[x][y]==1)
    //         return false;
    //     return true;
    // }
     int DIR[5] = {0, 1, 0, -1, 0};
    bool check(ll mid,int row,int col,vector<vector<int>>& cells)
    {
         ll sz=cells.size();
         vector<vector<bool>> grid(row, vector<bool>(col, 0)); 
        for (int i = 0; i <min(mid,sz); ++i) 
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        queue<pair<int, int>> bfs;
        for (int c = 0; c < col; ++c) 
        {
            if (grid[0][c] == 0) 
            { 
                bfs.push({0, c});
                grid[0][c] = 1; 
            }
        }
        while (bfs.size()>0) 
        {
            auto [r, c] = bfs.front(); bfs.pop();
            if (r == row - 1) 
                return true; 
            for (int i = 0; i < 4; ++i) 
            {
                int nr = r + DIR[i], nc = c + DIR[i+1];
                if (nr < 0 || nr == row || nc < 0 || nc == col || grid[nr][nc] == 1) continue;
                grid[nr][nc] = 1; 
                bfs.push({nr, nc});
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        ll l=1,r=1e18;
        ll ans=0;
        vector<vector<ll>> v(row,vector<ll>(col,0));
        // for(int i=0;i<cls.size();i++)
        // {
        //     v[cls[i][0]-1][cls[i][1]-1]=i+1;
        // }
        // for(ll i=0;i<r;i++)
        // {
        //     for(ll j=0;j<c;j++)
        //         cout<<v[i][j]<<" ";
        //     cout<<endl;
        // }
          //int l = 1, r = 1e18, ans = 0;
        while (l <= r)
        {
            ll mid = l + (r - l) / 2;
            if (check(mid, row, col, cells)) 
            {
                ans = mid; 
                l = mid + 1; 
            } 
            else 
                r = mid - 1; 
        }
        return ans;
    }
};