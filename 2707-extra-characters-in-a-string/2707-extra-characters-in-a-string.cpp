class Solution {
public:
    int dp[51];
    int f(int i,string& s,unordered_set<string>& st)
    {
        if(i==s.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        string str="";
        for(int idx=i;idx<s.size();idx++)
        {
            str+=s[idx];
            if(st.find(str)!=st.end())
            {
                int val=f(idx+1,s,st);
                if(val<ans)
                    ans=val;
            }
            else
            {
                int val=str.size()+f(idx+1,s,st);
                if(val<ans)
                    ans=val;
            }
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        unordered_set<string> st;
        for(auto t: dictionary)
            st.insert(t);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,s,st);
        return ans;
    }
};