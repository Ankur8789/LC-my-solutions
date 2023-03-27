class Solution {
public:
    int t[201][201];
    int f(int i,int j,vector<vector<int>>& v)
    {
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size())
            return INT_MAX-1;
        if(i==v.size()-1 && j==v[0].size()-1)
            return v[v.size()-1][v[0].size()-1];
        if(t[i][j]!=-1)
            return t[i][j];
        return t[i][j]=v[i][j]+min(f(i+1,j,v),f(i,j+1,v));
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        memset(t,-1,sizeof(t));
        int ans=f(0,0,grid);
        return ans;
    }
};