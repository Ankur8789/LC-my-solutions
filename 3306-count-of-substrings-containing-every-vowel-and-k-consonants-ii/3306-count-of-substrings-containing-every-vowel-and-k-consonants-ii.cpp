class Solution {
public:
    typedef long long ll;
    int iv(char ch){
        string str = "aeiou";
        return (str.find(ch) != string::npos);
    }
    bool check(map<char,ll>& mp,ll cn,int k,char ch){
        if(iv(ch)){
            mp[ch]--;
            if(mp[ch]==0)
                mp.erase(ch);
        }
        else cn--;
        bool ans=(mp.size()==5 && cn>=k);
        if(iv(ch))
            mp[ch]++;
        else cn++;
        return ans;
        
    }
    ll f(string& s,int k){
        ll i=0,j=0,n=s.size(),cn=0,ans=0;
        map<char,ll>mp;
        while(j<n){
            if(iv(s[j]))
               mp[s[j]]+=1;
            else cn++;
            while(check(mp,cn,k,s[i])){
                 if(iv(s[i])){
                     mp[s[i]]--;
                     if(mp[s[i]]==0)
                         mp.erase(s[i]);
                 }
                else{
                    cn--;
                }
                i++;
            }
            if(mp.size()==5 && cn>=k)
               ans+=(i+1);
               j++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        ll ans=-f(word,k+1)+f(word,k);
        return ans;
    }
};