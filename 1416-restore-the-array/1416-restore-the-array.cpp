class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    int dp[100001];
    int f(int i,string& s,int k)
    {
        if(i==s.size())
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        ll temp=0;
        for(int idx=i;idx<s.size();idx++)
        {
             temp*=10;
            temp+=s[idx]-'0';
            if(temp<=k)
            {
                ans+=f(idx+1,s,k);
                ans%=mod;
            }
            else
                break;
        }
        return dp[i]=ans;
    }
    int numberOfArrays(string s, int k) 
    {
        memset(dp,-1,sizeof(dp));
       int ans=f(0,s,k);
        return ans;
    }
};