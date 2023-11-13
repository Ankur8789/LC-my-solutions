class Solution {
public:
    int dp[1001][1001][4];
    int f(int i,int idx,int last,vector<int>& v)
    {
        if(idx==3)
            return 1;
        if(i==v.size())
            return 0;
        if(dp[i][last][idx]!=-1)
            return dp[i][last][idx];
        int ans=0;
        if(idx==0)
        {
            ans+=f(i+1,idx+1,i,v);
            ans+=f(i+1,idx,last,v);
        }
        else if(idx==1 || idx==2)
        {
            ans+=f(i+1,idx,last,v);
            if(v[last]>v[i])
                ans+=f(i+1,idx+1,i,v);
        }
        return dp[i][last][idx]=ans;
            
    }
    int numTeams(vector<int>& v) 
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(0,0,0,v);
       memset(dp,-1,sizeof(dp));
       reverse(v.begin(),v.end());
       ans+=f(0,0,0,v);
       return ans;
    }
};