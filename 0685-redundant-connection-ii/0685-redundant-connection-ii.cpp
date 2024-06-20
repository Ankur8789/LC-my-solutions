class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
       unordered_map<int,vector<int>> adj;
       int n=edges.size();
       vector<int> ideg(n+1);
       vector<int> ans;
       for(auto x: edges)
       {
           adj[x[0]].push_back(x[1]);
           ideg[x[1]]+=1;
       }
       for(auto x: edges)
       {
           // remove this edge
           ideg[x[1]]--;
           queue<int> q;
           vector<int> vis(n+1,0);
           for(int i=1;i<=n;i++)
           {
               if(ideg[i]==0)
               {
                   q.push(i);
                   vis[i]=1;
                   break;
               }
           }
           vector<int> tmpideg=ideg;
           while(q.size())
           {
               auto y=q.front();
               q.pop();
               int u=y;
               
               for(auto v: adj[u])
               {
                   if(u==x[0] && v==x[1])
                       continue;
                   else
                   {
                       if(vis[v]==0)
                       {
                           tmpideg[v]--;
                           if(tmpideg[v]==0)
                               q.push(v),vis[v]=1;
                       }
                   }
               }
           }
           bool ok=true;
           for(int i=1;i<=n;i++)
           {
               if(vis[i]==0)
               {
                   ok=false;
                   break;
               }
           }
           if(ok)
               ans=x;
           ideg[x[1]]++;
           
       }
        return ans;
       
       
    }
};