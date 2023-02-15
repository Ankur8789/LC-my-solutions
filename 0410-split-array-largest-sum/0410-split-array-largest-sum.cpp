typedef long long ll;
class Solution {
public:
    ll dp[1001][51];
    ll f(ll i,vector<ll>& pre,ll k,vector<int>& nums)
    {
       if(k==0)
       {  if(i!=0)
          return pre[pre.size()-1]-pre[i-1];
        else
            return pre[pre.size()-1];
       }
       if(i==pre.size())
           return 1e9;
       if(dp[i][k]!=-1)
           return dp[i][k];
       ll sum=0;
       ll ans=1e9;
       for(ll idx=i;idx<pre.size();idx++)
       {
          sum+=nums[idx];
          ans=min(ans,max(sum,f(idx+1,pre,k-1,nums)));
       }
        return dp[i][k]=ans;
    }
    int splitArray(vector<int>& nums, int k) 
    {     
        ll n=nums.size();
        vector<ll> pre(n);
        ll sm=0;
        for(ll i=0;i<n;i++)
        {
            sm+=nums[i];
            pre[i]=sm;
        }
        memset(dp,-1,sizeof(dp));
        ll ans=f(0,pre,k-1,nums);
        return ans;
    }
};