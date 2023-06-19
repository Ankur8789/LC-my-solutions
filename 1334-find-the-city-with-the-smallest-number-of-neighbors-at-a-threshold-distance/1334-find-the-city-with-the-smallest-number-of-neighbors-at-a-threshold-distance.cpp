class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) 
    {
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
            dis[i][i]=0;
        for(auto t: edges)
        {
            int u=t[0];
            int v=t[1];
            dis[u][v]=t[2];
            dis[v][u]=t[2];
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dis[i][k]==1e9 || dis[k][j]==1e9)
                        continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int res=1e9,ans=0;
        for(int i=0;i<n;i++)
        {
            int ct=0;
            for(int j=0;j<n;j++)
            {
                if(dis[i][j]<=dt)
                    ct++;
            }
            if(res>=ct)
            {
                ans=i;
                res=ct;
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //         cout<<dis[i][j]<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};