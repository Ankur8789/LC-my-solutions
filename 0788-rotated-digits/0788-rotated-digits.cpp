class Solution {
public:
    int dp[5][2][2];
    int f(int i,int tight,string& s,int taken,unordered_set<int>& st)
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
        int limit=9;
        if(tight)
            limit=s[i]-'0';
        int ans=0;
        for(int idx=0;idx<=limit;idx++)
        {
            if(st.find(idx)==st.end())
            {
                if(idx==0 || idx==1 || idx==8)
                {
                    if(taken)
                    {
                        ans+=f(i+1,(tight & (idx==limit)),s,taken,st);
                    }
                    else
                    {
                        ans+=f(i+1,(tight & (idx==limit)),s,taken,st);
                    }
                }
                else
                {
                    if(taken)
                    {
                        ans+=f(i+1,(tight & (idx==limit)),s,taken,st);
                    }
                    else
                    {
                        ans+=f(i+1,(tight & (idx==limit)),s,taken^1,st);
                    }
                }
            }
        }
        return dp[i][tight][taken]=ans;
    }
    int rotatedDigits(int n) 
    {
        unordered_set<int> st;
        st.insert(3);
        st.insert(4);
        st.insert(7);
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,s,0,st);
        return ans;
        
    }
};