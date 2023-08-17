class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    int sumDistance(vector<int>& nums, string s, int d) 
    {
       int n=nums.size();
       vector<ll> fin(n);
       for(int i=0;i<nums.size();i++)
       {
           if(s[i]=='R')
               fin[i]=nums[i]+d;
           else
               fin[i]=nums[i]-d;
       }
       sort(fin.begin(),fin.end());
       ll ps=0;
       ll ans=0;
       for(ll i=0;i<n;i++)
       {
           ans+=((i*1LL*fin[i])-ps);
           ans%=mod;
           ps+=fin[i];
       }
       return ans;
    }
};