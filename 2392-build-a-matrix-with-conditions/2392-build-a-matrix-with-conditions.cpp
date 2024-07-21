class Solution {
public:
    vector<int> adj1[10001];
    vector<int> adj2[10001];
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc)
    {     vector<int> i1(k+1);
          vector<vector<int>> ans(k,vector<int>(k,0));
          vector<vector<int>> temp;
         //row operations
        for(int i=0;i<rc.size();i++)
        {
            adj1[rc[i][0]].push_back(rc[i][1]);
            i1[rc[i][1]]++;
        }
       queue<int> q1;
        for(int i=1;i<=k;i++)
        {
           if(i1[i]==0)
               q1.push(i);
        }
       vector<int> vr;
         while(q1.size()>0)
         {
             int x=q1.front();
             q1.pop();
             vr.push_back(x);
             for(int i=0;i<adj1[x].size();i++)
             {
                 i1[adj1[x][i]]--;
                 if(i1[adj1[x][i]]==0)
                     q1.push(adj1[x][i]);
             }
         }
     cout<<vr.size()<<" ";
      if(vr.size()!=k)
          return temp;
     //col operations
     vector<int> i2(k+1);
     for(int i=0;i<cc.size();i++)
     {
         adj2[cc[i][0]].push_back(cc[i][1]);
         i2[cc[i][1]]++;
     }
     queue<int> q2;
     for(int i=1;i<=k;i++)
     {
         if(i2[i]==0)
             q2.push(i);
     }
     vector<int> vc;
     while(q2.size()>0)
     {
         int y=q2.front();
         q2.pop();
         vc.push_back(y);
         for(int i=0;i<adj2[y].size();i++)
         {
             i2[adj2[y][i]]--;
             if(i2[adj2[y][i]]==0)
                 q2.push(adj2[y][i]);
         }
     }
     cout<<vc.size()<<" ";
     if(vc.size()!=k)
         return temp;
     cout<<1<<" ";
     unordered_map<int,pair<int,int>> mp;
     for(int i=0;i<vr.size();i++)
         mp[vr[i]].first=i,cout<<vr[i]<<" ";
     for(int i=0;i<vc.size();i++)
         mp[vc[i]].second=i,cout<<vc[i]<<" ";
     for(auto it=mp.begin();it!=mp.end();it++)
         ans[it->second.first][it->second.second]=it->first;
      
     return ans;
     
     
        
    }
};