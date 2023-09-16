class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        unordered_map<int,vector<int>> adj;
        vector<int> ideg(n+1,0);
        for(auto t: edges)
        {
            adj[t[0]].push_back(t[1]);
            ideg[t[1]]++;
        }
        vector<int> ans;
        for(auto t: edges)
        {
            ideg[t[1]]--;
            vector<int> vis(n+1,0);
            queue<int> q;
            bool con=true;
            for(int i=1;i<=n;i++)
            {
                if(ideg[i]==0)
                {
                   q.push(i); 
                    vis[i]=1;
                    break;
                }
            }
            while(q.size()>0)
            {
                auto u=q.front();
                q.pop();
                for(auto v: adj[u])
                {
                    if(t[0]==u && t[1]==v)
                        continue;
                    if(vis[v]==1)
                    {
                        con=false;
                        break;
                    }
                    vis[v]=1;
                    q.push(v);
                     
                }
            }
             ideg[t[1]]++;
             for(int i=1;i<=n;i++)
             {
                 if(vis[i]==0)
                 {
                     con=false;
                     break;
                 }
             }
            if(con)
                ans=t;
            
        }
        return ans;
    }
};