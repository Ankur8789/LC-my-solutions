class Solution {
public:
   // vector<pair<int,int>> adj[10001];
    int dis[101][101];
    int m,n;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    bool isvalid(int x,int y)
    {
        if(x<0 || x>=m || y<0 || y>=n)
            return false;
        return true;
    }
    int minCost(vector<vector<int>>& grid) 
    {
        m=grid.size();
         n=grid[0].size();
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
                dis[i][j]=1e9;
        }
        set<pair<int,pair<int,int>>> st;
        dis[0][0]=0;
        st.insert({0,{0,0}});
        while(st.size()>0)
        {
            pair<int,pair<int,int>> p=*st.begin();
            st.erase(st.begin());
             
             int x=p.second.first;
             int y=p.second.second;
           // cout<<x<<" "<<y<<endl;
           //  cout<<endl;
             if(x==m-1 && y==n-1)
              continue;
            for(int i=0;i<4;i++)
            {  
                //cout<<dx[i]<<" "<<dy[i]<<endl;
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(!isvalid(nx,ny))
                    continue;
               // cout<<1<<endl;
                if(grid[x][y]==1)
                {
                    if(i==2)
                    {
                        if(dis[nx][ny]>dis[x][y])
                        {
                            dis[nx][ny]=dis[x][y];
                            st.insert({dis[x][y],{nx,ny}});
                        }
                    }
                    else
                    {
                        if(dis[nx][ny]>dis[x][y]+1)
                        {
                            dis[nx][ny]=dis[x][y]+1;
                            st.insert({dis[nx][ny],{nx,ny}});
                        }
                    }
                }
               else if(grid[x][y]==2)
                {
                    if(i==3)
                    {
                        if(dis[nx][ny]>dis[x][y])
                        {
                            dis[nx][ny]=dis[x][y];
                            st.insert({dis[x][y],{nx,ny}});
                        }
                    }
                    else
                    {
                        if(dis[nx][ny]>dis[x][y]+1)
                        {
                            dis[nx][ny]=dis[x][y]+1;
                            st.insert({dis[nx][ny],{nx,ny}});
                        }
                    }
                }
               else if(grid[x][y]==3)
                {
                    if(i==0)
                    {
                        if(dis[nx][ny]>dis[x][y])
                        {
                            dis[nx][ny]=dis[x][y];
                            st.insert({dis[x][y],{nx,ny}});
                        }
                    }
                    else
                    {
                        if(dis[nx][ny]>dis[x][y]+1)
                        {
                            dis[nx][ny]=dis[x][y]+1;
                            st.insert({dis[nx][ny],{nx,ny}});
                        }
                    }
                }
               else if(grid[x][y]==4)
                {
                    if(i==1)
                    {
                        if(dis[nx][ny]>dis[x][y])
                        {
                            dis[nx][ny]=dis[x][y];
                            st.insert({dis[x][y],{nx,ny}});
                        }
                    }
                    else
                    {
                        if(dis[nx][ny]>dis[x][y]+1)
                        {
                            dis[nx][ny]=dis[x][y]+1;
                            st.insert({dis[nx][ny],{nx,ny}});
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                cout<<dis[i][j]<<" ";
            cout<<endl;
        }
        if(dis[m-1][n-1]==1e9)
            return -1;
        return dis[m-1][n-1];
        
    }
};