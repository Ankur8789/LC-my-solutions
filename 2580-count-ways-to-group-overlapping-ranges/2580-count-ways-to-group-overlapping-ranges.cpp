typedef long long ll;
const ll mod=1e9+7;
ll mpw(ll base, ll exp, ll M)
{
    // O(LOGEXP) TIME
    if (exp == 0)
        return 1;
    ll res = mpw(base, exp / 2, M);
    if (exp % 2 == 1)
        return (((res * res) % M) * base) % M;
    else
        return (res * res) % M;
}
class Solution {
public:
    int countWays(vector<vector<int>>& ranges) 
    {
        // ix();
        ll cnt=1;
        sort(ranges.begin(),ranges.end());
        vector<ll> tot;
        ll curr=ranges[0][1];
        for(ll i=1;i<ranges.size();i++)
        {
            if(curr>=ranges[i][0])
            {
                curr=max(curr,1LL*ranges[i][1]);
            }
            else
            {
                // cout<<curr<<" "<<ranges[i][0]<<endl;
                cnt++;
                curr=ranges[i][1];
            }
        }
        ll ans=mpw(2,cnt,mod);
        return int(ans);
        
    }
};