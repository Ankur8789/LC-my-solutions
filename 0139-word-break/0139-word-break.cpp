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
            ans|=x;
           
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> st;
        for(auto t:wordDict)
            st.insert(t);
        memset(dp,-1,sizeof(dp));
        bool ans=f(0,s,st);
        return ans;
    }
};