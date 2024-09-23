class Solution {
public:
    unordered_set<string> st;
    int dp[51];
    int f(int i,string& s){
        if(i>=s.size())
            return 0;
        auto& x=dp[i];
        if(x!=-1)
            return x;
        int ans=1e9;
        string res="";
        for(int j=i;j<s.size();j++){
            res+=s[j];
            if(st.count(res)){
                ans=min(ans,f(j+1,s));
            }
            else{
               ans=min(ans,j-i+1+f(j+1,s)); 
            }
        }
        return x=ans;
    }
    int minExtraChar(string s, vector<string>& dict) {
        for(auto x: dict)
            st.insert(x);
        for(int i=0;i<=s.size()+1;i++)dp[i]=-1;
        int ans=f(0,s);
        return ans;
    }
};