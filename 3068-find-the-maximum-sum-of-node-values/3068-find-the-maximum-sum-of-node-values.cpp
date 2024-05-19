class Solution {
public:
    typedef long long ll;
    #define rev(v) reverse(begin(v),end(v));
    #define srt(v) sort(begin(v),end(v));
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        ll ans=0;
        vector<ll> diff;
        for(auto x: nums)
        {
            ans+=x;
            diff.push_back((x^k)-x);
        }
        srt(diff);
        rev(diff);
        cout<<ans<<endl;
        for(auto x: diff)
            cout<<x<<' ';
        ll res=ans;
        for(ll i=1;i<diff.size();i+=2)
            ans+=diff[i]+diff[i-1],res=max(res,ans);
        return res;
        
    }
};