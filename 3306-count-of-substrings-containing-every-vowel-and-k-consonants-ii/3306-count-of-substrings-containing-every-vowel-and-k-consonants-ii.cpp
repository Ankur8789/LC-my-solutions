class Solution {
public:
    typedef long long ll;
    int iv(char ch){
        string str = "aeiouAEIOU";
        return (str.find(ch) != string::npos);
    }
    ll f(string s,int k){
        ll i=0,j=0,n=s.size(),cn=0;
        string w=s;
        ll ans=0;
        map<char,ll>mp;
        while(j<n){
            if(iv(s[j])){
                mp[s[j]]+=1;
            }
            else{
                cn++;
            }
            while(mp.size()==5 && cn>k){
                if(iv(w[i])){
                    mp[w[i]]--;
                    if(mp[w[i]]==0)
                        mp.erase(w[i]);
                }
                else
                    cn--;
                i++;
            }
            ans+=(j-i+1);
            j+=1;
        }
        return ans;
    }
    long long countOfSubstrings(string w, int k) {
      return -f(w,k-1)+f(w,k);
    }
};