class Solution {
public:
    bool check(int x,int y,vector<string>& grid)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return 0;
        if(grid[x][y]=='#')
            return 0;
        return 1;
    }
    int ppc(int n)
    {
        int c = 0;
        for (; n; ++c)
           n &= n - 1;
        return c;
    }
    vector<pair<int,int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    int shortestPathAllKeys(vector<string>& grid) 
    {
        queue<pair<int,pair<int,int>>> q;
        int m=grid.size();
        int n=grid[0].size();
        int keys=0;
        for(int i=0;i<m;i++)
        {
           for(int j=0;j<n;j++)
           {
               int val=grid[i][j]-'a';
               if(val>=0 && val<=5)
                   keys++;
               if(grid[i][j]=='@')
                   q.push({0,{i,j}});
           }
        }
        cout<<keys<<endl;
        vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(100,0)));
        int lvl=0;
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                auto p=q.front();
                 q.pop();
                int i=p.second.first;
                int j=p.second.second;
                int msk=p.first;
                if(ppc(msk)==keys)
                    return lvl;
                for(auto t: dirs)
                {
                    int ni=i+t.first;
                    int nj=j+t.second;
                    if(check(ni,nj,grid))
                    {
                        if(grid[ni][nj]>='A' && grid[ni][nj]<='F')
                        {
                            if((msk>>(grid[ni][nj]-'A'))&1)
                            {
                                int tmpmsk=msk|(1<<(grid[ni][nj]-'A'));
                                if(vis[ni][nj][tmpmsk]==0)
                                {
                                    q.push({tmpmsk,{ni,nj}});
                                    vis[ni][nj][tmpmsk]=1;
                                }
                            }
                        }
                        else if(grid[ni][nj]>='a' && grid[ni][nj]<='f')
                        {
                            int tmpmsk=msk|(1<<(grid[ni][nj]-'a'));
                            if(vis[ni][nj][tmpmsk]==0)
                            {
                                q.push({tmpmsk,{ni,nj}});
                                vis[ni][nj][tmpmsk]=1;
                            }
                        }
                        else
                        {
                            if(vis[ni][nj][msk]==0)
                            {
                                q.push({msk,{ni,nj}});
                                vis[ni][nj][msk]=1;
                            }
                        }
                    }
                }
                
            }
         lvl++;  
            
        }
        return -1;
    }
};