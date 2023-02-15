class Solution {
public:
    typedef long long ll;
    ll dp[501];
    ll f(ll i,int k,vector<int>& arr)
    {
        if(i==arr.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        ll ans=0;
        ll mx=INT_MIN;
        for(ll idx=i;idx<i+k;idx++)
        {
            if(idx==arr.size())
                break;
            mx=max(mx,1LL*arr[idx]);
            ans=max(ans,mx*(idx-i+1)+f(idx+1,k,arr));
        }
        return dp[i]=ans;
       
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {  memset(dp,-1,sizeof(dp));
       int ans=f(0,k,arr);
        return ans;
    }
};