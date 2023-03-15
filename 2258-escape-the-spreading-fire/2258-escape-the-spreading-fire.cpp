class Solution {
public:
    typedef long long ll;
    ll m,n;
    bool check(ll i,ll j,vector<vector<int>>& grid,vector<vector<ll>>& vis)
    {
        if(i<0 || j<0 || i>=m || j>=n)
            return false;
        if(grid[i][j]!=0)
            return false;
        if(vis[i][j]==1)
            return false;
        return true;
    }
    bool hey(ll mid,vector<vector<ll>>& fdis,vector<vector<int>>& grid)
    {
        vector<vector<ll>> pdis(m,vector<ll>(n,1e10));
        vector<vector<ll>> visx(m,vector<ll>(n,0));
        queue<pair<ll,ll>> qp;
        qp.push({0,0});
        pdis[0][0]=mid;
        visx[0][0]=1;
        while(qp.size()>0)
        {
            pair<ll,ll> p=qp.front();
            qp.pop();
            ll x=p.first;
            ll y=p.second;
            if(check(x+1,y,grid,visx))
            {    
                if(x+1==m-1 && y==n-1 && pdis[x][y]+1==fdis[x+1][y])
                    return true;
                if(pdis[x][y]+1<fdis[x+1][y])
                {
                    visx[x+1][y]=1;
                    pdis[x+1][y]=pdis[x][y]+1;
                    qp.push({x+1,y});
                }
            }
            if(check(x-1,y,grid,visx))
            {
                 if(x-1==m-1 && y==n-1 && pdis[x][y]+1==fdis[x-1][y])
                    return true;
                if(pdis[x][y]+1<fdis[x-1][y])
                {
                    visx[x-1][y]=1;
                    pdis[x-1][y]=pdis[x][y]+1;
                    qp.push({x-1,y});
                }
            }
            if(check(x,y+1,grid,visx))
            {
                  if(x==m-1 && y+1==n-1 && pdis[x][y]+1==fdis[x][y+1])
                    return true;
                if(pdis[x][y]+1<fdis[x][y+1])
                {
                    visx[x][y+1]=1;
                    pdis[x][y+1]=pdis[x][y]+1;
                    qp.push({x,y+1});
                }
            }
            if(check(x,y-1,grid,visx))
            {
                 if(x==m-1 && y-1==n-1 && pdis[x][y]+1==fdis[x][y-1])
                    return true;
                if(pdis[x][y]+1<fdis[x][y-1])
                {
                    visx[x][y-1]=1;
                    pdis[x][y-1]=pdis[x][y]+1;
                    qp.push({x,y-1});
                }
            }
        }
        return pdis[m-1][n-1]!=1e10;
    }
        
        
        
    int maximumMinutes(vector<vector<int>>& grid)
    {
           
         //for fire
         queue<pair<ll,ll>> qf;
        m=grid.size();
        n=grid[0].size();
        vector<vector<ll>> fdis(m,vector<ll>(n,1e10));
        vector<vector<ll>> vis(m,vector<ll>(n,0));
        for(ll i=0;i<m;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    qf.push({i,j});
                    fdis[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        while(qf.size()>0)
        {
            pair<ll,ll> p=qf.front();
            qf.pop();
            ll x=p.first;
            ll y=p.second;
            if(check(x+1,y,grid,vis))
            {
                vis[x+1][y]=1;
                fdis[x+1][y]=fdis[x][y]+1;
                qf.push({x+1,y});
            }
            if(check(x-1,y,grid,vis))
            {
                vis[x-1][y]=1;
                fdis[x-1][y]=fdis[x][y]+1;
                qf.push({x-1,y});
            }
            if(check(x,y+1,grid,vis))
            {
                vis[x][y+1]=1;
                fdis[x][y+1]=fdis[x][y]+1;
                qf.push({x,y+1});
            }
            if(check(x,y-1,grid,vis))
            {
                vis[x][y-1]=1;
                fdis[x][y-1]=fdis[x][y]+1;
                qf.push({x,y-1});
            }
            
        }
        
       // the fire has spread 
       // 
       //  vector<vector<int>> pdis(m,vector<int>(n,1e9));
       //  vector<vector<int>> visx(m,vector<int>(n,0));
       //  queue<pair<int,int>> qp;
       //  qp.push({0,0});
       //  pdis[0][0]=0;
       //  visx[0][0]=1;
       //  while(qp.size()>0)
       //  {
       //      pair<int,int> p=qp.front();
       //      qp.pop();
       //      int x=p.first;
       //      int y=p.second;
       //      if(check(x+1,y,grid,visx))
       //      {
       //          if(pdis[x][y]+1<=fdis[x+1][y])
       //          {
       //              visx[x+1][y]=1;
       //              pdis[x+1][y]=pdis[x][y]+1;
       //              qp.push({x+1,y});
       //          }
       //      }
       //      if(check(x-1,y,grid,visx))
       //      {
       //          if(pdis[x][y]+1<=fdis[x-1][y])
       //          {
       //              visx[x-1][y]=1;
       //              pdis[x-1][y]=pdis[x][y]+1;
       //              qp.push({x-1,y});
       //          }
       //      }
       //      if(check(x,y+1,grid,visx))
       //      {
       //          if(pdis[x][y]+1<=fdis[x][y+1])
       //          {
       //              visx[x][y+1]=1;
       //              pdis[x][y+1]=pdis[x][y]+1;
       //              qp.push({x,y+1});
       //          }
       //      }
       //      if(check(x,y-1,grid,visx))
       //      {
       //          if(pdis[x][y]+1<=fdis[x][y-1])
       //          {
       //              visx[x][y-1]=1;
       //              pdis[x][y-1]=pdis[x][y]+1;
       //              qp.push({x,y-1});
       //          }
       //      }
       //  }
       //  if(pdis[m-1][n-1]==fdis[m-1][n-1] && pdis[m-1][n-1]!=1e9)
       //      return 0;
       // // if(pdis)
       //  if(fdis[m-1][n-1]==1e9)
       //      return 1e9;
       //  if(pdis[m-1][n-1]==1e9)
       //      return -1;
        ll l=0,r=1e9;
        ll ans=-1;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(hey(mid,fdis,grid))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1; 
        }
        cout<<hey(1e9,fdis,grid)<<endl;
        
        return ans;
        
    }
};