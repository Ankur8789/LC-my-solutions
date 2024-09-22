class Solution {
public:
    typedef long long ll;
    
    long long validSubstringCount(string word1, string word2) {
        ll ans=0;
        vector<ll> curr(26);
        for(auto x: word2)
            curr[x-'a']+=1;
        vector<ll> hsh(26);
        ll i=0,j=0,n=word1.size();
        while(j<n){
            hsh[word1[j]-'a']+=1;
            bool ok=false;
            while(1){
               bool chk=true;
                for(ll x=0;x<26;x++){
                    if(hsh[x]<curr[x])
                        chk=false;
                }
                if(chk){
                    hsh[word1[i]-'a']--,i++;
                }
                else
                    break;
            }
            ans+=i;
            j++;
        }
        return ans;
    }
};