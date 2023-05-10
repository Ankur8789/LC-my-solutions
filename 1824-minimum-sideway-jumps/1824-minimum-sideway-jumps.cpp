class Solution {
public:
    int dp[500005][4];
    
    int f(int i,int lane,vector<int>& obs)
    {
        if(i==obs.size()-1)
            return 0;
        if(dp[i][lane]!=-1)
            return dp[i][lane];
        int ans=INT_MAX;
        if(obs[i+1]==lane)
        {
            if(lane==1)
            {
               if(obs[i]!=2)
               ans=min(ans,1+f(i,2,obs));
               if(obs[i]!=3)
               ans=min(ans,1+f(i,3,obs));
            }
            else if(lane==2)
            {
                if(obs[i]!=1)
               ans=min(ans,1+f(i,1,obs));
               if(obs[i]!=3)
               ans=min(ans,1+f(i,3,obs));
            }
            else
            {
                if(obs[i]!=2)
               ans=min(ans,1+f(i,2,obs));
               if(obs[i]!=1)
               ans=min(ans,1+f(i,1,obs));
            }
        }
        else
        {
            if(lane==1)
            {
               ans=min(ans,f(i+1,lane,obs));
               // ans=min(ans,1+f(i,2,obs));
               // ans=min(ans,1+f(i,3,obs));
            }
            else if(lane==2)
            {
                ans=min(ans,f(i+1,lane,obs));
            }
            else
            {
                ans=min(ans,f(i+1,lane,obs));
            }
        }
        return dp[i][lane]=ans;
    }
    int minSideJumps(vector<int>& obs) 
    { 
        memset(dp,-1,sizeof(dp));
        int ans=f(0,2,obs);
        return ans;
    }
};