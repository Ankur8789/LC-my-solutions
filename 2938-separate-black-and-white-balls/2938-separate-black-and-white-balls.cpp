class Solution {
public:
    typedef long long ll;
    long long minimumSteps(string s) {
        ll n = s.size();
        vector<ll> ones;
        for(int i=0;i<n;i++){
            if(s[i] == '1')
                ones.push_back(i);
        }
        if(ones.size() == 0)
            return 0;
        ll ans = 0;
        ans += n-1 - ones.back();
        ll curr = n-2;
        for(ll i=ones.size()-2;i>=0;i--){
            ans += curr - ones[i];
            curr--;
        }
        return ans;
    }
};