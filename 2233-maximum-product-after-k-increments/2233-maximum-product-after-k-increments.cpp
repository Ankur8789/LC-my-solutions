typedef long long ll;
int mod=1e9+7;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=0;i<nums.size();i++)
            pq.push(nums[i]);
        while(k--)
        {
            ll x=pq.top();
            pq.pop();
            ++x;
            pq.push(x);
        }
        ll pr=1;
        while(pq.size()>0)
        {
            int x=pq.top();
            pr*=x;
            pr%=mod;
            pq.pop();
        }
        return pr%mod;
        
    }
};