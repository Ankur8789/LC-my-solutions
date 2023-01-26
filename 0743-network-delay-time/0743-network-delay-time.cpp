class Solution {
public:
    int dis[1001];
    int vis[1001];
    vector<pair<int,int>> adj[1001];
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {   
         for(int i=1;i<=n;i++)
        {  dis[i]= INT_MAX;
            
        }
         for(auto t: times)
         {
             adj[t[0]].push_back({t[1],t[2]});
         }
        dis[k]=0;
        multiset<pair<int,int>> ms;
        ms.insert({0,k});
        
        while(ms.size()>0)
        {
            pair<int,int> p=*ms.begin();
            ms.erase(ms.begin());
            if(vis[p.second]==1)
                continue;
            vis[p.second]=1;
            for(auto t: adj[p.second])
            {
                int a=t.first;
                int wt=t.second;
                if(dis[a]>dis[p.second]+wt)
                {
                    dis[a]=dis[p.second]+wt;
                    ms.insert({dis[a],a});
                }
            }
        }
        int ans=0;
        bool flag=true;
        for(int i=1;i<=n;i++)
        {  cout<<dis[i]<<" "; 
            if(dis[i]==INT_MAX)
                flag=false;
            ans=max(ans,dis[i]);
            
        }
        if(!flag)return -1;
     return ans;
            
     
     
        
    }
};