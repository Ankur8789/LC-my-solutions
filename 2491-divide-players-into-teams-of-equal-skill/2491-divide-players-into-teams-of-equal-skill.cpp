class Solution {
public:
    typedef long long ll;
    long long dividePlayers(vector<int>& skill) {
        map<ll,ll> mp;
        sort(begin(skill),end(skill));
        ll n=skill.size();
        ll ans=0;
        for(ll i=0;i<n/2;i++){
           mp[skill[i]+skill[n-i-1]];
           ans+=skill[i]*skill[n-i-1];
        }
        if(mp.size()==1)
            return ans;
        else
            return -1;
    }
};