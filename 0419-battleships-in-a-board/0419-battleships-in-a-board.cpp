class Solution {
public:
    int vis[201][201];
    void dfsud(int i,int j,vector<vector<char>>& b)
    {  
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size())
        return;
        if(b[i][j]=='.')
        return ;
        if(vis[i][j]==1)
            return ;
        vis[i][j]=1;
        dfsud(i-1,j,b);
        dfsud(i+1,j,b);
        
    }
    void dfslr(int i,int j,vector<vector<char>>& b)
    {  
        if(i<0 || j<0 || i>=b.size() || j>=b[0].size())
        return;
        if(b[i][j]=='.')
        return ;
        if(vis[i][j]==1)
            return ;
        vis[i][j]=1;
        dfslr(i,j-1,b);
        dfslr(i,j+1,b);
        
    }
    int countBattleships(vector<vector<char>>& b) 
    {
       int m=b.size();
       int n=b[0].size();
        int cc=0;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(b[i][j]=='X'&& vis[i][j]==0)
               {
                    dfslr(i,j,b);
                    vis[i][j]=0;
                    dfsud(i,j,b);
                    ++cc;
               }
           }
       }
        return cc;
    }
};