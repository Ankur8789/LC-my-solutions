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
    int minimumEffortPath(vector<vector<int>>& he) 
    {
        m=he.size();
        n=he[0].size();
        vector<vector<int>> dis(m,vector<int>(n,1e9));
        dis[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        q.push({0,0,0});
        while(q.size()>0)
        {
            auto x=q.top();
            q.pop();
            for(auto t: dir)
            {
                int nx=x[1]+t.first;
                int ny=x[2]+t.second;
                if(check(nx,ny) && dis[nx][ny]>max(x[0],abs(he[x[1]][x[2]]-he[nx][ny])))
                {
                    dis[nx][ny]=max(x[0],abs(he[x[1]][x[2]]-he[nx][ny]));
                    q.push({dis[nx][ny],nx,ny});
                }
            }
        }
        return dis[m-1][n-1];
        
    }
};