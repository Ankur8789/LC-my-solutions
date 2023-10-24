class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& langs, vector<vector<int>>& fri) 
    {
        unordered_map<int,set<int>> rec;
        for(int i=0;i<langs.size();i++)
        {
           vector<int> temp=langs[i];
           for(int j=0;j<temp.size();j++)
               rec[i].insert(temp[j]);
        }
        
        int m=fri.size();
        vector<int> notreq(m);
        for(int i=0;i<fri.size();i++)
        {
            int u=fri[i][0];
            int v=fri[i][1];
            --u;
            --v;
            set<int> s1=rec[u];
            set<int> s2=rec[v];
            for(auto t: s1)
            {
                if(s2.find(t)!=s2.end())
                {
                    // cout<<t<<endl;
                    notreq[i]=1;
                    break;
                }
            }
        }
        // for(auto t: notreq)cout<<t<<" ";
        int res=1e5;
        for(int i=1;i<=n;i++)
        {
          int cnt=0;
          vector<int> ins(langs.size());
          for(int j=0;j<fri.size();j++)
          {
              if(notreq[j]==1)
                  continue;
              int u=fri[j][0]-1;
              int v=fri[j][1]-1;
              if(rec[u].find(i)==rec[u].end() && ins[u]==0)
              {
                  cnt++;
                  ins[u]=1;
              }
              if(rec[v].find(i)==rec[v].end() && ins[v]==0)
              {
                  cnt++;
                  ins[v]=1;
              }
          }
          res=min(res,cnt);
        }
        return res;
        
    }
};