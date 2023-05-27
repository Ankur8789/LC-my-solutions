class Solution {
public:
    int dp[1001][1001][2];
    int f(int i,int j,int turn,vector<int>& st,vector<int>& pref,vector<int>& suff)
    {
        if(i==j)
            return 0;
        if(dp[i][j][turn]!=-1)
            return dp[i][j][turn];
        if(turn)
        {
          int pf=0,sf=0;
          if(i==0)
              pf=pref[j]-st[i];
          else
              pf=pref[j]-pref[i];
          if(j==st.size()-1)
              sf=suff[i]-st[j];
          else
              sf=suff[i]-suff[j];
          return dp[i][j][turn]=max(pf+f(i+1,j,turn^1,st,pref,suff),sf+f(i,j-1,turn^1,st,pref,suff));
        }
        else
        {
          int pf=0,sf=0;
          if(i==0)
              pf=pref[j]-st[i];
          else
              pf=pref[j]-pref[i];
          if(j==st.size()-1)
              sf=suff[i]-st[j];
          else
              sf=suff[i]-suff[j];
          return dp[i][j][turn]=min(-pf+f(i+1,j,turn^1,st,pref,suff),-sf+f(i,j-1,turn^1,st,pref,suff)) ;
        }
    }
    int stoneGameVII(vector<int>& st)
    {
       int sum=0;
       for(auto t: st)
           sum+=t;
        int n=st.size();
        vector<int> pref(n),suff(n);
        int ps=0;
        for(int i=0;i<n;i++)
        {
            ps+=st[i];
            pref[i]=ps;
            suff[i]=sum;
            sum-=st[i];
        }
        memset(dp,-1,sizeof(dp));
       int ans=f(0,n-1,1,st,pref,suff);
        return ans;
       
    }
};