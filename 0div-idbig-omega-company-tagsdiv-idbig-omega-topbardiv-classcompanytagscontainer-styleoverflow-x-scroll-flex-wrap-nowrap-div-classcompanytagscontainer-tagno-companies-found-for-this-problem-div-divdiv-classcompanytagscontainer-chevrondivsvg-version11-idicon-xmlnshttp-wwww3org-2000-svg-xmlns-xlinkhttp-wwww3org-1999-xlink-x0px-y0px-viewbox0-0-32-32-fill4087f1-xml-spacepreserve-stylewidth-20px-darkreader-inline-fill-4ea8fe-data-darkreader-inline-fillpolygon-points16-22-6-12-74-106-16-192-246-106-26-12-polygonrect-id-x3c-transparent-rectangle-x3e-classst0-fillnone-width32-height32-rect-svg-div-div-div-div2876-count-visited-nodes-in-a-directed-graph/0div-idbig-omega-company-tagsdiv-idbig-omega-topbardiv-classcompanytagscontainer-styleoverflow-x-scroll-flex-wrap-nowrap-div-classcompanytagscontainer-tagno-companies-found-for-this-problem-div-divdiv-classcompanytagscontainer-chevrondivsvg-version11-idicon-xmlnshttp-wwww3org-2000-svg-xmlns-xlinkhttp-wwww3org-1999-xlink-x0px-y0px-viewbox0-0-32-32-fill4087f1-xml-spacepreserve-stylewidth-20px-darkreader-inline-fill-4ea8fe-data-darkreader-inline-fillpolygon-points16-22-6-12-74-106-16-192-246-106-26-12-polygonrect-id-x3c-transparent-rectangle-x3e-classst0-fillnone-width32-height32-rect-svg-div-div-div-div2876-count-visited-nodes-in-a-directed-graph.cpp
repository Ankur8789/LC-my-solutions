class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> dist;
    vector<int> countVisitedNodes(vector<int>& edges)
    {
        int n=edges.size();
        vector<int> ideg(n);
        for(int i=0;i<n;i++)
        {
            ideg[edges[i]]++;
            adj[i].push_back(edges[i]);
        }
        vector<int> order;
        queue<int> q;
        vector<int> vis(n);
        for(int i=0;i<n;i++)
        {
            if(ideg[i]==0)
            {
                q.push(i);
                vis[i]=1;
            }
        }
        while(q.size()>0)
        {
            int u=q.front();
            q.pop();
            order.push_back(u);
            for(auto v: adj[u])
            {
                ideg[v]--;
                if(ideg[v]==0)
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ideg[i]>0 && vis[i]==0)
            {
                int curr=i;
                int cnt=0;
                vector<int> temp;
                while(vis[curr]==0)
                {
                    cnt++;
                    vis[curr]=1;
                    temp.push_back(curr);
                    curr=adj[curr][0];
                }
                for(auto t: temp)dist[t]=cnt;
            }
        }
        reverse(begin(order),end(order));
        for(int i=0;i<order.size();i++)
            dist[order[i]]=1+dist[adj[order[i]][0]];
        vector<int> ans;
        for(int i=0;i<n;i++)ans.push_back(dist[i]);
        return ans;
        
        
        
    }
};