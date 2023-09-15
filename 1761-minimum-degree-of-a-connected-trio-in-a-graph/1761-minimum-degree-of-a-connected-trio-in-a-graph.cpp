class Solution {
public:
    unordered_map<int,vector<int>> adj;
    int res=INT_MAX;
    unordered_map<int,int> vis;
    map<pair<int,int>,int> mp;
    // void dfs(int x)
    // {
    //     vis[x]=1;
    //     vector<int> child=adj[x];
    //     for(int i=0;i<child.size();i++)
    //     {
    //         for(int j=i+1;j<child.size();j++)
    //         {
    //             int c1=child[i];
    //             int c2=child[j];
    //             if(mp.find({c1,c2})==mp.end())
    //                 continue;
    //             int ed=adj[x].size()-2;
    //             ed+=adj[c1].size()-2;
    //             ed+=adj[c2].size()-2;
    //             // cout<<x<<" "<<ed<<endl;
    //             res=min(res,ed);
    //         }
    //     }
    //     for(auto t: child)
    //     {
    //         if(vis.find(t)==vis.end())
    //             dfs(t);
    //     }
    // }
    int min(int a,int b)
    {
        if(a<b)
            return a;
        else
            return b;
    }
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> vec(n+1,vector<int>(n+1));
       
        for(auto t: edges)
        {
            if(mp.find({t[0],t[1]})!=mp.end())
                continue;
            // cout<<t[0]<<" -> "<<t[1]<<endl;
            vec[t[0]][t[1]]+=1;
            vec[t[1]][t[0]]+=1;
            adj[t[0]].push_back(t[1]);
            adj[t[1]].push_back(t[0]);
            mp[{t[0],t[1]}]++;
            mp[{t[1],t[0]}]++;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(vec[i][j] && vec[j][k] && vec[i][k])
                        res=min(res,adj[i].size()+adj[j].size()+adj[k].size()-6);
                }
            }
        }
        return res=(res==INT_MAX)?-1:res;
    }
};