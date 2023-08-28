class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
       unordered_map<int,vector<int>> adj;
       for(int i=0;i<edges.size();i++)
       {
           if(edges[i]!=-1)
               adj[i].push_back(edges[i]);
       }
       // node1 se bfs
       int n=edges.size();
        vector<int> vis(n),dis1(n,1e9),dis2(n,1e9);
        multiset<pair<int,int>> ms;
        dis1[node1]=0;
        ms.insert({0,node1});
        while(ms.size()>0)
        {
            auto t=*ms.begin();
            ms.erase(ms.begin());
            int d=t.first;
            int u=t.second;
            for(auto t: adj[u])
            {
                if(dis1[t]>d+1)
                {
                    if(ms.count({dis1[t],t}))
                        ms.erase({dis1[t],t});
                    dis1[t]=d+1;
                    ms.insert({dis1[t],t});
                }
            }
        }
        // node 2
        ms.insert({0,node2});
        dis2[node2]=0;
        while(ms.size()>0)
        {
            auto t=*ms.begin();
            ms.erase(ms.begin());
            int d=t.first;
            int u=t.second;
            for(auto t: adj[u])
            {
                if(dis2[t]>d+1)
                {
                    if(ms.count({dis2[t],t}))
                        ms.erase({dis2[t],t});
                    dis2[t]=d+1;
                    ms.insert({dis2[t],t});
                }
            }
        }
        int ans=-1,pp=1e9;
        for(int i=0;i<n;i++)
        {
            if(dis1[i]==1e9 || dis2[i]==1e9)
                continue;
            int tem=max(dis1[i],dis2[i]);
            if(tem<pp)
            {
                pp=tem;
                ans=i;
            }
        }
        return ans;
    }
};