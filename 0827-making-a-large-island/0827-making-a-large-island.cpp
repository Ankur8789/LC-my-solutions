typedef long long ll;
ll parent[300001];
ll siz[300001];
void make(ll v)
{
    parent[v] = v;
    siz[v] = 1;
}
ll find(ll v)
{
    if (parent[v] == v)
        return v;
    else // path compresssion
        return parent[v] = find(parent[v]);
}
void Union(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    { // union by size
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
class Solution {
public:
    vector<pair<ll,ll>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
    bool check(ll x,ll y,vector<vector<int>>& grid)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid.size())
            return false;
        if(grid[x][y]==0)
            return false;
        return true;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
       int k=0;
       map<pair<ll,ll>,ll> index;
       ll n=grid.size();
       for(ll i=0;i<n;i++)
       {
           for(ll j=0;j<n;j++)
           {
               index[{i,j}]=k++;
           }
       }
       for(ll i=0;i<k;i++)make(i);
       for(ll i=0;i<n;i++)
       {
           for(ll j=0;j<n;j++)
           {
               if(grid[i][j]==1)
               {
                  for(auto t: dirs)
                  {
                      ll x=i+t.first;
                      ll y=j+t.second;
                      if(check(x,y,grid))
                      {
                          // cout<<index[{i,j}]<<" "<<index[{x,y}]<<endl;
                          Union(index[{i,j}],index[{x,y}]);
                      }
                  }
               }
           }
       }
        ll res=0;
      for(ll i=0;i<k;i++)
      {
          // cout<<" "<<find(i)<<" "<<siz[i]<<endl;
          res=max(res,siz[i]);
      }
      for(ll i=0;i<n;i++)
      {
         for(ll j=0;j<n;j++)
         {
             if(grid[i][j]==0)
             {
                
                unordered_map<ll,ll> ref;
                 ll cc=0;
                 for(auto t: dirs)
                 {
                     ll x=i+t.first;
                     ll y=j+t.second;
                     if(check(x,y,grid))
                     {
                          ref[find(index[{x,y}])]=siz[find(index[{x,y}])];
                          // cout<<find(index[{x,y}])<<" "<<siz[index[{x,y}]]<<endl;
                     }
                    
                 }
                 for(auto t: ref)
                     cc+=t.second;
                 cc++;
                 res=max(res,cc);
             }
         }
          
      }
        return res;
       
    }
};