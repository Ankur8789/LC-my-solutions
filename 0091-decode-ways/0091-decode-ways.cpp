class Solution {
public:
    int dp[101];
    int f(int i,string& s)
    {
        if(i>=s.size())
            return 1;
        auto& x=dp[i];
        if(x!=-1)
            return x;
        int ans=0;
        if(s[i]!='0')
        ans+=f(i+1,s);
        string str=s.substr(i,2);
        int val=stoi(str);
        if(val>=10 && val<=26)
        ans+=f(i+2,s);
        return x=ans;
    }
    int numDecodings(string s) 
    {
       memset(dp,-1,sizeof(dp));
       int ans=f(0,s);
       return ans;
    }
};