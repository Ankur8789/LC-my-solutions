class Solution {
public:
    int dp[301];
    bool f(int i,string& s,unordered_set<string>& st)
    {
        if(i==s.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        string str="";
        bool ans=false;
        for(int idx=i;idx<s.size();idx++)
        {
            str+=s[idx];
            if(st.find(str)!=st.end())
                ans|=f(idx+1,s,st);
            if(ans)
                return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> st;
        for(auto t: wordDict)
            st.insert(t);
        memset(dp,-1,sizeof(dp));
        bool ans=f(0,s,st);
        return ans;
    }
};