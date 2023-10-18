class Solution {
public:
    vector<int> adj[50001];
    int minimumTime(int n, vector<vector<int>>& rs, vector<int>& t) 
    {  vector<int> indeg(n+1,0);
       vector<int> tx(n+1,0);
        for(int i=0;i<rs.size();i++)
        {
            adj[rs[i][0]].push_back(rs[i][1]);
            indeg[rs[i][1]]++;
        }
        queue<int> q;
      for(int i=1;i<=n;i++)
      {
          if(indeg[i]==0)
          {
              tx[i]=t[i-1];
              q.push(i);
          }
      }
     int ans=0;
     while(q.size()>0)
     {
            int x=q.front();
             q.pop();
            // mx=max(mx,t[x-1]);
             for(auto i:adj[x])
             {
                 indeg[i]--;
                tx[i]=max(tx[i],tx[x]);
                 if(indeg[i]==0)
                 {
                     q.push(i);
                     tx[i]+=t[i-1];
                 }
             }
         
        
     }
     for(int i=1;i<=n;i++)cout<<tx[i]<<" ";
        
     return *max_element(begin(tx),end(tx));
        
    }
};