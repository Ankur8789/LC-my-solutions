class Solution {
public:
    vector<int> adj[100001];
    int dfs(int x,int fa,int s,long long&ans)
    {
        int siz=1;
        for(int v:adj[x])if(v!=fa)siz+=dfs(v,x,s,ans);
        if(x!=0)ans+=siz/s+(siz%s!=0);
        return siz;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats)
    {
        int n=roads.size()+1;
        long long ans=0;
       for(int i=0;i<roads.size();i++)
       {
           adj[roads[i][1]].push_back(roads[i][0]);
           adj[roads[i][0]].push_back(roads[i][1]);
       }
        
        dfs(0,-1,seats,ans);
        return ans;
    }
};