int ppc(int n)
{
    int c = 0;
    for (; n; ++c)
        n &= n - 1;
    return c;
}
class Solution {
public:
    int dp[13][1<<13];
    vector<vector<int>> dis;
    int f(int n,int msk,int u)
    {
        if(ppc(msk)==n)
            return 0;
        if(dp[u][msk]!=-1)
            return dp[u][msk];
        int res=1e6;
        for(int i=0;i<n;i++)
        {
            if(!((msk>>i)&1))
            {
                res=min(res,dis[u][i]+f(n,msk|(1<<i),i));
            }
        }
        return dp[u][msk]=res;
    }
    int shortestPathLength(vector<vector<int>>& graph) 
    {
         int n=graph.size();
         dis.resize(n,vector<int>(n,1e5));
         for(int i=0;i<n;i++)
             dis[i][i]=min(dis[i][i],0);
         for(int i=0;i<graph.size();i++)
         {
             int u=i;
             vector<int> child=graph[i];
             for(auto v: child)
             {
                 dis[u][v]=1;
                 dis[v][u]=1;
             }
         }
         for(int via=0;via<n;via++)
         {
             for(int u=0;u<n;u++)
             {
                 for(int v=0;v<n;v++)
                 {
                     dis[u][v]=min(dis[u][v],dis[u][via]+dis[via][v]);
                 }
             }
         }
        int res=1e9;
        for(int i=0;i<n;i++)
        {
           memset(dp,-1,sizeof(dp));
           res=min(res,f(n,0|(1<<i),i));
        }
        return res;
        
    }
};