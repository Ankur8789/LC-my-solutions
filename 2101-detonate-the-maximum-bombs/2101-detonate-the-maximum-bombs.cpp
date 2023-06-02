class Solution {
public:
    int vis[101];
    vector<int> adj[101];
    int maxbombs;
    int count;
    
    void dfs(int v)
    { count++;
     maxbombs=max(maxbombs,count);
        vis[v]=1;
      for(int i=0;i<adj[v].size();i++)
      {
          if(vis[adj[v][i]]==0)
          {
             dfs(adj[v][i]); 
          }
      }
     
    }
    
    int maximumDetonation(vector<vector<int>>& bombs)
    {  count=0;maxbombs=0;
        for(int i=0;i<bombs.size();i++)
        {
            for(int j=0;j<bombs.size();j++)
            {  if(i==j)continue;
                long long a=(pow(abs(bombs[i][0]-bombs[j][0]),2)+pow(abs(bombs[i][1]-bombs[j][1]),2));
                long long b=bombs[i][2];
                if(a<=b*b)
                    adj[i+1].push_back(j+1);
            }
        }
        for(int i=1;i<=bombs.size();i++)
        {
            if(vis[i]==0){
                dfs(i);
                for(int j=0;j<101;j++)vis[j]=0;
                count=0;
            }
        }
     return maxbombs;
    }
};