class Solution {
public:
    double t[26][26][101]={0.0};
   
    double f(int n,int k,int i,int j)
    {   if(i<0 || i>=n || j<0 || j>=n)
            return 0;
        if(k==0)
            return 1;
        if(t[i][j][k]!=0)
            return t[i][j][k];
        
        double ans=0;
        ans+=f(n,k-1,i+1,j+2);
        ans+=f(n,k-1,i+2,j+1);
        ans+=f(n,k-1,i+1,j-2);
        ans+=f(n,k-1,i+2,j-1);
        ans+=f(n,k-1,i-1,j+2);
        ans+=f(n,k-1,i-1,j-2);
        ans+=f(n,k-1,i-2,j-1);
        ans+=f(n,k-1,i-2,j+1);
        return  t[i][j][k]=ans/8;
        
    }
    double knightProbability(int n, int k, int row, int column) 
    {
        double ans=f(n,k,row,column);
        return ans;
    }
};