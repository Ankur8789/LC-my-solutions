class Solution {
public:
    int dp[11][2][11];
    int f(int i,int tight,string& s,int cnt)
    {
        if(i==s.size())
            return cnt;
        if(dp[i][tight][cnt]!=-1)
            return dp[i][tight][cnt];
        int last=9;
        if(tight)
            last=s[i]-'0';
        int ans=0;
        for(int idx=0;idx<=last;idx++)
        {
            if(idx==1)
            {
                ans+=f(i+1,(tight&(idx==(s[i]-'0'))),s,cnt+1);
            }
            else
            {
                ans+=f(i+1,(tight&(idx==(s[i]-'0'))),s,cnt);
            }
        }
        return dp[i][tight][cnt]=ans;
    }
    int countDigitOne(int n) 
    {
       memset(dp,-1,sizeof(dp));
       string num=to_string(n);
       int ans=f(0,1,num,0);
       return ans;
    }
};