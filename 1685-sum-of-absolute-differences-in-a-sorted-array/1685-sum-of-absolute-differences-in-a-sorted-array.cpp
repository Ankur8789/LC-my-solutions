#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
class Solution {
public:
    typedef long long ll;
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        fastio();
        ll n=nums.size();
        vector<ll> pre(n);
        ll ps=0;
        for(ll i=0;i<n;i++)
        {
            ps+=nums[i];
            pre[i]=ps;
        }
        vector<int> ans;
        for(ll i=0;i<n;i++)
        {
            ll x=nums[i]*i;
            x-=pre[i]-nums[i];
            ll y=pre[n-1]-pre[i];
            y-=nums[i]*(n-i-1);
            ans.push_back(x+y);
        }
        return ans;
        
    }
};