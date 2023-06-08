class Solution {
public:
    const int mod=1e9+7;
    int dp[30][401][2];
    int f(int n,string& num,int mn,int mx,int tight,int currsum)
    {
       if(n==0)
       {
           if(currsum>=mn && currsum<=mx)
               return 1;
           else
               return 0;
       }
       if(dp[n][currsum][tight]!=-1)
           return dp[n][currsum][tight];
      int tot=0;
      int limit=9;
      if(tight==1)
          limit=num[num.size()-n]-'0';
      for(int i=0;i<=limit;i++)
      {
          tot+=f(n-1,num,mn,mx,tight&(i==limit),currsum+i);
          tot%=mod;
      }
        return dp[n][currsum][tight]=tot;
       
    }
    
    int count(string num1, string num2, int min_sum, int max_sum) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(num2.size(),num2,min_sum,max_sum,1,0);
        memset(dp,-1,sizeof(dp));
        ans-=f(num1.size(),num1,min_sum,max_sum,1,0);
        ans+=mod;
        ans%=mod;
        int cc=0;
        for(auto t: num1)
            cc+=t-'0';
        if(cc<=max_sum && cc>=min_sum)
            ans++;
        
        return ans;
    }
};