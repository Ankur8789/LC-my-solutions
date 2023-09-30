#define ll long long int
class Solution {
public:


    ll nCr(ll n, ll r) {
        double sum = 1;
        for(ll i = 1; i <= r; i++){
            sum = sum * (n - r + i) / i;
        }
        return (ll)sum;
    }


    int countKSubsequencesWithMaxBeauty(string s, int k) {
        ll mod = 1e9+7;
        map<char,ll>m;
        for(ll i=0;i<s.size();i++) {
            m[s[i]]++;
        }
        map<ll,ll>mp;
        for(auto it = m.begin(); it!= m.end(); it++) {
            mp[it->second]++;
        }
        if(m.size() < k) {
            return 0;
        }
        ll ans = 1;
        auto it1 = mp.end();
        it1--;
        // for(auto it2 = mp.begin(); it2 != mp.end();it2++) {
        //     cout<<it2->first<<" "<<it2->second<<"\n";
        // }

        ll check = k;
        while(check>0) {
            ll freq = it1->first;
            ll freqNum = it1->second;
            // cout<<freq<<" "<<freqNum<<"\n";
            if(freqNum <= check) {
                // cout<<freqNum<<" "<<check<<"\n";
                for(ll p=1; p<=freqNum; p++) {
                    ans = (ans%mod * freq%mod)%mod;
                }
                cout<<ans<<"\n";
            } else {
                ll x = 1;
                for(ll p=1; p<=check; p++) {
                    x = (x%mod * freq%mod)%mod;
                    // cout<<x<<'\n';
                }
                x = (x%mod * nCr(freqNum, check)%mod)%mod;
                ans = (ans%mod * x%mod)%mod;
            }
            check -= freqNum;
            // cout<<check<<"\n";
            it1--;
        }
        // cout<<nCr(2,1)<<"\n";
        // for(int i=1;i<=k;i++) {
        //     ans = (ans%mod * it1->first%mod)%mod;
        //     ans = (ans%mod * it1->second%mod)%mod;
        //     it1--;
        // }

        return ans;
    }
};