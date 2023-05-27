class Solution {
public:
    int dp[501][501];
    int f(int i,int j,vector<int>& sv,vector<int>& pref,vector<int>& suff)
    {
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=0;
        for(int idx=i;idx<j;idx++)
        { 
            int pf=0,sf=0;
            if(i==0)
                pf=pref[idx];
            else
                pf=pref[idx]-pref[i-1];
            if(j==sv.size()-1)
                sf=suff[idx+1];
            else
                sf=suff[idx+1]-suff[j+1];
            if(pf>sf)
            {
               ans=max(ans,sf+f(idx+1,j,sv,pref,suff));
            }
            else if(pf==sf)
            {
                ans=max({ans,pf+f(i,idx,sv,pref,suff),sf+f(idx+1,j,sv,pref,suff)});
            }
            else
            {
                ans=max(ans,pf+f(i,idx,sv,pref,suff));
            }
        }
        return dp[i][j]=ans;
    }
    int stoneGameV(vector<int>& sv) 
    {
        int n=sv.size();
        vector<int> pref(n),suff(n);
        int ps=0;
        int sum=0;
        for(auto t: sv)
            sum+=t;
        for(int i=0;i<n;i++)
        {
            ps+=sv[i];
            pref[i]=ps;
            suff[i]=sum;
            sum-=sv[i];
        }
        // for(int i=0;i<n;i++)cout<<pref[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)cout<<suff[i]<<" ";
        memset(dp,-1,sizeof(dp));
        int ans=f(0,n-1,sv,pref,suff);
        return ans;
    }
};