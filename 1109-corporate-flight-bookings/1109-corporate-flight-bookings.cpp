#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
class Solution {
public:
    typedef long long ll;
    vector<int> corpFlightBookings(vector<vector<int>>& bk, int n) 
    {  
        fastio() ;
        vector<ll> pre(n+2);
        for(auto t:bk)
        {
            ll x=--t[0];
            ll y=--t[1];
            ll z=t[2];
            pre[x]+=z;
            pre[y+1]-=z;
        }
        vector<int> ans;
        ll ps=0;
        for(ll i=0;i<n;i++)
        {
            ps+=pre[i];
            ans.push_back(ps);
        }
        return ans;
        
    }
};