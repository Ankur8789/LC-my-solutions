typedef long long ll;
vector<ll> zf(string s){
    ll n = s.size();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; i++){
        if (i < r){
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
class Solution {
public:
    int isPrefixOfWord(string sen, string sw) {
        vector<string> vec;
        int i=0;
        while(i<sen.size()){
            string str="";
            while(i<sen.size() && sen[i]!=' ')
                str+=sen[i++];
            vec.push_back(str);
            i++;
        }
        int sz=sw.size();
        for(int i=0;i<vec.size();i++){
            vector<ll> v=zf(sw+'#'+vec[i]);
            if(v[sz+1]==sz)
                return i+1;
        }
        return -1;
    }
};