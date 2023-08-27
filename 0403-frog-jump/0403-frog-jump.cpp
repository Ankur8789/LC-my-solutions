class Solution {
public:
    int dp[2001][2001];
    bool f(int i,int last,vector<int>& stones)
    {
        if(i==stones.size()-1)
            return true;
        if(dp[i][last]!=-1)
            return dp[i][last];
        if(i==0)
        {
            if(stones[i+1]!=1)
                return dp[i][last]=false;
            return dp[i][last]=f(i+1,i,stones);
        }
        else
        {
            int jump=stones[i]-stones[last];
            int a=0,b=0,c=0;
            a=jump+1;
            b=jump;
            c=jump-1;
            bool ans=false;
            for(int idx=i+1;idx<stones.size();idx++)
            {
                if(stones[idx]-stones[i]>a)
                    break;
                if(stones[idx]-stones[i]==a && a>0)
                    ans|=f(idx,i,stones);
                if(stones[idx]-stones[i]==b && b>0)
                    ans|=f(idx,i,stones);
                if(stones[idx]-stones[i]==c && c>0)
                    ans|=f(idx,i,stones);
                if(ans)
                    return dp[i][last]=true;
            }
            return dp[i][last]=false;
        }
        
        
    }
    bool canCross(vector<int>& stones) 
    {
        memset(dp,-1,sizeof(dp));
        bool ans=f(0,0,stones);
        return ans;
    }
};