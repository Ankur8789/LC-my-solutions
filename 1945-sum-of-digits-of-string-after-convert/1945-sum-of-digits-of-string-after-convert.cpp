class Solution {
public:
    int getLucky(string s, int k){
        int ans=0;
        string num="";
        for(auto x: s){
            num+=to_string(x-'a'+1);
        }
        while(k--){
            ans=0;
            for(auto x: num)
                ans+=(x-'0');
            num=to_string(ans);
        }
        return ans;
            
    }
};