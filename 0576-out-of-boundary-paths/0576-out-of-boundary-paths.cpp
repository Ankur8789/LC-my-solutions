class Solution {
public:
    const int M=1e9+7;
    typedef long long ll;
    int t[51][51][51];
    ll f(int i,int j,int m,int n,int k)
    {
        if(i<0 || j<0 || i==m || j==n)
            return 1;
        if(k==0)
            return 0;
        if(t[i][j][k]!=-1)
            return t[i][j][k];
        return t[i][j][k]=(f(i+1,j,m,n,k-1)%M+f(i-1,j,m,n,k-1)%M+f(i,j+1,m,n,k-1)%M+f(i,j-1,m,n,k-1)%M)%M;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {  memset(t,-1,sizeof(t));
        ll ans=f(startRow,startColumn,m,n,maxMove)%M;
        return ans;
    }
};