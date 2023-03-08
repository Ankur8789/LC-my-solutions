#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
class Solution {
public:
    int dp[301];
    bool f(int i,string& s,unordered_set<string>& st)
    {
        if(i==s.length())
            return true; 
        if(dp[i]!=-1)
            return dp[i];
        string temp="";
        bool ans=false;
        for(int idx=i;idx<s.length();idx++)
        {
            temp+=s[idx];
            if(st.find(temp)==st.end())
                continue;
            bool x=f(idx+1,s,st);
           if(x)
               return dp[i]=true;
           
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        fastio();
        unordered_set<string> st;
        for(auto t:wordDict)
            st.insert(t);
        memset(dp,-1,sizeof(dp));
        bool ans=f(0,s,st);
        return ans;
    }
};