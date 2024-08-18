class Solution {
public:
    typedef long long ll;
    int nthUglyNumber(int n) 
    {
        set<ll> s;
        ll ans=1;
        s.insert(ans);
        for(ll i=0;i<n;i++)
        {
            ans=*(s.begin());
            s.erase(ans);
            s.insert(ans*2);
            s.insert(ans*3);
            s.insert(ans*5);
        }
        return ans;
        
    }
};