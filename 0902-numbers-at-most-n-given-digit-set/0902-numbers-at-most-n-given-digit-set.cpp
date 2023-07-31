class Solution {
public:
    int dp[10][2][2];
    int f(int i,int tight,int taken,string& s,unordered_set<string>& st)
    {
        if(i==s.size())
        {
            if(taken)
                return 1;
            else
                return 0;
        }
        if(dp[i][tight][taken]!=-1)
            return dp[i][tight][taken];
        int ub=9;
        if(tight)
            ub=s[i]-'0';
        int ans=0;
        for(int idx=0;idx<=ub;idx++)
        {
           if(taken==0)
           {
               if(idx==0)
                   ans+=f(i+1,tight&(idx==ub),taken,s,st);
               else
               {
                   if(st.find(to_string(idx))!=st.end())
                   {
                       ans+=f(i+1,tight&(idx==ub),taken^1,s,st);
                   }
               }
                   
           }
           else
           {
               if(st.find(to_string(idx))!=st.end())
               {
                   ans+=f(i+1,tight&(idx==ub),taken,s,st);
               }
           }
        }
        return dp[i][tight][taken]=ans;
            
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) 
    {
        unordered_set<string> st;
        for(auto t: digits)
        {
            st.insert(t);
        }
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,0,s,st);
        return ans;
    }
};