class Solution {
public:
    vector<vector<int>> vis;
    int tx, ty , bx , by;
    void dfs(int i , int j, vector<vector<int>>& land)
    {
        if(i >= land.size() || j >= land[0].size())
            return ;
        if(land[i][j] == 0 || vis[i][j] == 1)
            return ;
        vis[i][j] = 1;
        if(i > bx)
        {
            bx = i;
            by = j;
        }
        else if(i == bx)
            by = max(by , j);
        dfs(i+1,  j ,land);
        dfs(i , j+1, land);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) 
    {
       int m = land.size();  
       int n = land[0].size();
       vis.resize(m,vector<int>(n , 0));
       vector<vector<int>> ans;
       for(int i = 0; i < m ; i++)
       {
          for(int j = 0; j < n ;j++)
          {
             if(vis[i][j] == 0 && land[i][j] == 1)
             {
                 tx = i;
                 ty = j;
                 bx = i;
                 by = j;
                 dfs(i , j , land);
                 ans.push_back({tx , ty , bx , by});
             }
          }
       }
       return ans;
       
    }
};