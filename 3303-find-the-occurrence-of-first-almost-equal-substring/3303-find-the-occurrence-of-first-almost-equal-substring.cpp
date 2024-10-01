class Solution {
public:
    vector<int> zf(string s) {
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
    int minStartingIndex(string s, string pat) {
        vector<int> z1=zf(pat+'$'+s);
        reverse(begin(s),end(s));
        reverse(begin(pat),end(pat));
        vector<int> z2=zf(pat+'$'+s);
        reverse(begin(s),end(s));
        reverse(begin(pat),end(pat));
        int n=s.size(),m=pat.size();
        for(int i=m+1;i<n+m;i++){
            // cout<<z1[i]<<" "<<z2[i]<<endl;
            int sz=z1[i];
            if(sz>=m)
                return i-m-1;
            int l=i;
            int r=i+m-1;
            // cout<<l<<" "<<r<<endl;
            if(r>n+m)
                break;
            int revidx=n+m-r+m+1;
            // l+=m+1;
            // cout<<revidx<<endl;
            
            sz+=z2[revidx];
            // cout<<sz+1<<" "<<m<<endl;
            if(sz+1>=m)
                return l-m-1;
        }
        return -1;
    }
};