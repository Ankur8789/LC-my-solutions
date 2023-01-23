class Solution {
public:
    vector<int> adj[1001];
    int a[1001];
    
    int findJudge(int n, vector<vector<int>>& trust) 
    {   int ans=-1;
        for(int i=0;i<trust.size();i++)
        {
            adj[trust[i][0]].push_back(trust[i][1]);
             a[trust[i][1]]++;
            //adj[trust[i][1]].push_back(trust[i][1]);
        }
          for(int i=1;i<=n;i++)
          {
              if(adj[i].size()==0 && a[i]==n-1)
              {
                  ans=i;break;
              }
          }
     return ans;
    }
};