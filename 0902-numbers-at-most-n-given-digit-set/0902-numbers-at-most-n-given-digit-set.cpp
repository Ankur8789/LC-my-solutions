class Solution {
public:
    int dp[11][2][2];
    int f(int i,int tight,unordered_set<string>& st,string s,int taken)
    {
        if(i==s.size())
            return 1;
        if(dp[i][tight][taken]!=-1)
            return dp[i][tight][taken];
        int ans=0;
        int limit=9;
        if(tight)
            limit=s[i]-'0';
        for(int idx=0;idx<=limit;idx++)
        {
           if(idx==0)
           {
              if(taken==0)
              {
                  ans+=f(i+1,(tight & (idx==limit)),st,s,taken);
              }
           }
           else
           {
               if(st.find(to_string(idx))!=st.end())
               {
                   if(taken)
                   {
                       ans+=f(i+1,(tight & (idx==limit)),st,s,taken);
                   }
                   else
                   {
                       ans+=f(i+1,(tight & (idx==limit)),st,s,taken^1);
                   }
               }
           }
        }
        return dp[i][tight][taken]=ans;
        
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) 
    {
        // reverse(digits.begin(),digits.end());
        // // digits.push_back("0");
        // reverse(digits.begin(),digits.end());
        unordered_set<string> st;
        for(auto t: digits)
            st.insert(t);
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,st,s,0)-1;
        return ans;
    }
};