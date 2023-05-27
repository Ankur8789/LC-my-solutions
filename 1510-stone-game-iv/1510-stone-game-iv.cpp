class Solution {
public:
    typedef long long ll;
    ll dp[100001][2];
    bool f(int n,int turn,vector<ll>& sq)
    {
        if(n<0)
            return false;
        if(n==0)
        {
            if(turn)
                return false;
            else
                return true;
        }
        if(dp[n][turn]!=-1)
            return dp[n][turn];
        if(turn)
        {
            bool ans=false;
           for(ll i=0;i<sq.size();i++)
           {
               if(n<sq[i])
                   break;
               ans|=f(n-sq[i],turn^1,sq);
               if(ans)
                   return dp[n][turn]=ans;
           }
            return dp[n][turn]=ans;
        }
        else
        {
            bool ans=true;
            for(ll i=0;i<sq.size();i++)
            {
                if(n<sq[i])
                    break;
                ans&=f(n-sq[i],turn^1,sq);
            }
            return dp[n][turn]=ans;
        }
    }
    bool winnerSquareGame(int n) 
    {
        vector<ll> sq;
        for(ll i=1;i<=1e5;i++)
            sq.push_back(i*i);
        memset(dp,-1,sizeof(dp));
        bool ans=f(n,1,sq);
        return ans;
    }
};