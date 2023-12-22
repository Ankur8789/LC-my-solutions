class Solution {
public:
    typedef long long ll;
    long long countPairs(vector<int>& nums, int k)
    {
       ll ans=0;
       // a * b % k == 0
       map<ll,ll> mp;
       for(auto u: nums)
       {
           int xgcd=__gcd(u,k);
           for(auto t: mp)
           {
               if((xgcd*t.first)%k==0)
                   ans+=t.second;
           }
           mp[xgcd]++;
       }
       return ans;
        
    }
};