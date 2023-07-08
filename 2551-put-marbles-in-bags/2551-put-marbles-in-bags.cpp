typedef long long ll;
class Solution {
public:
    
    long long putMarbles(vector<int>& weights, int k) 
    {
        ll ans=0;
        ll n=weights.size();
        ll mx=weights[0]+weights[n-1];
        ll mn=weights[0]+weights[n-1];
        vector<ll> diff;
        for(ll i=0;i<n-1;i++)
            diff.push_back(weights[i]+weights[i+1]);
        sort(diff.begin(),diff.end());
        ll i=0,j=n-1;
        ll cc=0;
        for(ll i=0;i<k-1;i++)
        {
            mn+=diff[i];
            mx+=diff[diff.size()-1-i];
        }
       return (mx-mn);
        
    }
};