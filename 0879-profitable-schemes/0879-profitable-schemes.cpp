class Solution {
public:
    typedef long long ll;
    const ll mod=1e9+7;
    
    int dp[101][1001][101][2];
    int f(int i,int mp, vector<int>& g, vector<int>& p,int pr,int n,bool mila)
    {
         if(n==0)
         {
             if(mila)
                return 1;
             else
             {
                if(pr>=mp)
                    return 1;
                 else
                     return 0;
             }
         }
        if(i==g.size())
        {
            if(mila)
                return 1;
            else
            {
                if(pr>=mp)
                    return 1;
                else
                    return 0;
            }
        }
        if(dp[i][pr][n][mila]!=-1)
            return dp[i][pr][n][mila];
        int ans=0;
        ans+=f(i+1,mp,g,p,pr,n,mila);
        ans%=mod;
        if(g[i]<=n)
        {
            if(mila)
            {
                ans+=f(i+1,mp,g,p,pr,n-g[i],mila);
                ans%=mod;
            }
            else
            {
               if(pr+p[i]>=mp)
                   ans+=f(i+1,mp,g,p,pr+p[i],n-g[i],1);
                else
                   ans+=f(i+1,mp,g,p,pr+p[i],n-g[i],0);
                ans%=mod;
                
            }
        }
        return dp[i][pr][n][mila]=ans;
        
    }
    int profitableSchemes(int n, int mp, vector<int>& g, vector<int>& p) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,mp,g,p,0,n,0);
        return ans;
    }
};