class Solution {
public:
    int f(int i,int k,vector<vector<int>>& ev,vector<vector<int>>& dp)
    {
        if(k==0)
            return 0;
        if(i==ev.size())
           return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans=0;
        ans=max(ans,f(i+1,k,ev,dp));
        int l=i+1,r=ev.size()-1;
        int res=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(ev[mid][0]>ev[i][1])
            {
               res=mid;
               r=mid-1;
            }
            else
               l=mid+1;
        }
        int temp=ev[i][2];
        if(res!=-1)
            temp+=f(res,k-1,ev,dp);
        ans=max(ans,temp);
        return dp[i][k]=ans;
    }
    int maxValue(vector<vector<int>>& ev, int k) 
    {
       sort(ev.begin(),ev.end());
       int n=ev.size();
       vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
       int ans=f(0,k,ev,dp);
       return ans;
    }
};