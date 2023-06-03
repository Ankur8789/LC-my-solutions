class Solution {
public:
    vector<pair<int,int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
    int m,n;
    bool check(int x,int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    int minimumTime(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        if(grid[0][1]>grid[0][0]+1 && grid[1][0]>1)
            return -1;
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        dis[0][0]=0;
        q.push({0,0,0});
        while(q.size()>0)
        {
            auto x=q.top();
            int dist=x[0];
            // int pari=x[1];
            // int parj=x[2];
            int i=x[1];
            int j=x[2];
            q.pop();
            for(auto t: dir)
            {
                int ni=i+t.first;
                int nj=j+t.second;
                if(check(ni,nj))
                {
                    if(dist+1>=grid[ni][nj])
                    {
                        if(dist+1<dis[ni][nj])
                        {
                           dis[ni][nj]=dist+1;
                           q.push({dist+1,ni,nj});
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        //back and forth
                        int tmp=grid[ni][nj];
                        if((tmp+dist+1)&1)
                            tmp++;
                        if(tmp<dis[ni][nj])
                        {
                            dis[ni][nj]=tmp;
                            q.push({tmp,ni,nj});
                        }
                    }
                }
            }
        }
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<dis[i][j]<<" ";
        //     cout<<endl;
        // }
        if(dis[m-1][n-1] == 1e9)
            return -1;
        return dis[m-1][n-1];
        
    }
};