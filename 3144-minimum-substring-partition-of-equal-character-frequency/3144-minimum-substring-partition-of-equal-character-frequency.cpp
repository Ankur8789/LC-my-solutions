class Solution {
public:
    int dp[1001];
    bool check(vector<int>& fre)
    {
       int pre =-1;
        for(auto t: fre)
        {
            if(t>0)
            {
                if(pre==-1)
                    pre=t;
                else
                {
                    if(pre!=t)
                        return 0;
                }
            }
        }
        return 1;
    }
    int f(int i,string& s)
    {
        if(i==s.size())
            return 0;
        auto& x=dp[i];
        if(x!=-1)
            return x;
        int ans=1e9;
        vector<int> fre(26);
        for(int idx=i;idx<s.size();idx++)
        {
            fre[s[idx]-'a']++;
            if(check(fre))
                ans=min(ans,1+f(idx+1,s));
        }
        return x=ans;
    }
    int minimumSubstringsInPartition(string s) 
    {
         memset(dp,-1,sizeof(dp));
         int ans=f(0,s);
         return ans;
    }
};