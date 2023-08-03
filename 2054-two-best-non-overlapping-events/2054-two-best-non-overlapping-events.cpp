class Solution {
public:
    int dp[100001][3];
    static bool cmp(vector<int>&a,vector<int>& b)
    { 
        if(a[0]==b[0] && a[1]==b[1])
            return a[2]>b[2];
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int f(int i,vector<vector<int>>&ev,int t)
    {
        if(t==0)
            return 0;
        if(i==ev.size())
            return 0;
        if(dp[i][t]!=-1)
            return dp[i][t];
        int ans=0;
        ans=max(ans,f(i+1,ev,t));
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
            temp+=f(res,ev,t-1);
        ans=max(ans,temp);
        // cout<<i<<" "<<ans<<endl;
        return dp[i][t]=ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(),events.end(),cmp);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,events,2);
        return ans;
    }
};