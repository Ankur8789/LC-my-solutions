class Solution {
public:
    vector<int> z_function(string s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    typedef long long ll;
    long long sumScores(string s) {
        ll ans=0;
        // this is z function .... kisi v index se shuru hone wala wo largest substring
        // that is also a prefix so by default this condition is seen
        vector<int> zf=z_function(s);
        for(auto x:zf)
            ans+=x;
        ans+=s.size();
        return ans;
    }
};