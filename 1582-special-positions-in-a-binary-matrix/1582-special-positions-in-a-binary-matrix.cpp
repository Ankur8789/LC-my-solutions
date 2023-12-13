class Solution {
public:
    bool check(vector<vector<int>>& mat,int x,int y)
    {
        int cnt=0;
        for(int i=0;i<mat[0].size();i++)
            cnt+=(mat[x][i]==1?1:0);
        // int cnt=0;
        for(int i=0;i<mat.size();i++)
            cnt+=(mat[i][y]==1?1:0);
        return cnt==2;
    }
    int numSpecial(vector<vector<int>>& mat) 
    {
         int ans=0;
         int m=mat.size();
         int n=mat[0].size();
         for(int i=0;i<m;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if(mat[i][j]==1)
                 {
                     if(check(mat,i,j))
                         ++ans;
                 }
             }
         }
        return ans;
    }
};