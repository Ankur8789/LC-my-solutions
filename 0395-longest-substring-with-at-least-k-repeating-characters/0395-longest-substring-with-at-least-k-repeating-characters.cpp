class Solution {
public:
    bool check(map<char,int>& mp,int k){
        for(auto x: mp){
            if(x.second<k)
                return false;
        }
        return true;
    }
    int longestSubstring(string s, int k) {
        int n=s.size(),ans=0;
        set<char> st;
        for(auto x: s)
            st.insert(x);
        int maxi=st.size();
        for(int len=1;len<=maxi;len++){
            map<char,int> mp;
            int i=0,j=0;
            while(j<n){
                mp[s[j]]++;
                while(mp.size()>len){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                if(mp.size() && check(mp,k))
                  ans=max(ans,j-i+1);
                 j++;
            }
            
        }
        return ans;
        
    }
};