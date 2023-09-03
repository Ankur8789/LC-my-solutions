class Solution {
public:
    int t[101][101];
    int f(int i,int j,int m,int n)
    {
        if(i<0 || j==n || j<0 || i==m )
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(t[i][j]!=-1)
            return t[i][j];
        return t[i][j]=f(i+1,j,m,n)+f(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) 
    {
        memset(t,-1,sizeof(t));
        int ans=f(0,0,m,n);
        return ans;
        
    }
};