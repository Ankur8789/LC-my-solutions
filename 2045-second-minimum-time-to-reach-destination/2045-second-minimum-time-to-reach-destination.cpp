class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) 
    {
        vector<vector<int>> dis(n+1,vector<int>(2,1e9));
        unordered_map<int,vector<int>> adj;
        for(auto x: edges)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        multiset<vector<int>> ms;
        ms.insert({0,0,1});
        
        dis[1][0]=0;
        // dis[1][1]=0;
        while(ms.size())
        {
            auto x=*ms.begin();
            ms.erase(ms.begin());
            int d=x[0];
            int t=x[1];
            int u=x[2];
            int parity=x[0]/change;
            if(parity&1)
                d+=change-d%change;
            d+=time;
            // cout<<d<<endl;
            for(auto v: adj[u])
            {
               if(dis[v][0]==1e9 || dis[v][1]==1e9)
               {
                   if(dis[v][0]==1e9)
                       dis[v][0]=d,ms.insert({dis[v][0],t,v});
                   else
                   {
                      if(dis[v][0]>d)
                          dis[v][1]=dis[v][0],dis[v][0]=d,ms.insert({dis[v][0],t,v});
                      else if(dis[v][0]<d)
                          dis[v][1]=d,ms.insert({dis[v][1],t,v});
                   }
               }
               else
               {
                  if(dis[v][0]>d)
                  {
                      dis[v][1]=dis[v][0];
                      dis[v][0]=d;
                      ms.insert({dis[v][0],t,v});
                  }
                  else if(dis[v][1]>d)
                  {
                     dis[v][1]=d;
                     ms.insert({dis[v][1],t,v});
                  }
               }
            }    
        }
        cout<<dis[n][0]<<" "<<dis[n][1];
        return dis[n][1];
    }
};