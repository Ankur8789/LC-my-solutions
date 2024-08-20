class Solution {
public:
    int dp[101][2][201];
    int f(int i,int turn,int m,vector<int>& piles){
        if(i==piles.size())
            return 0;
        auto&x=dp[i][turn][m];
        if(x!=-1)
            return x;
        int ans=0,n=piles.size();
        if(turn){
            int tk=0,sum=0;
            for(int idx=i;idx<min(n,i+2*m);idx++){
                tk++;
                sum+=piles[idx];
                ans=max(ans,sum+f(idx+1,turn^1,max(m,tk),piles));
            }
        }
        else{
            int tk=0;
            ans=1e9;
            for(int idx=i;idx<min(n,i+2*m);idx++){
                tk++;
                ans=min(ans,f(idx+1,turn^1,max(m,tk),piles));
            }
        }
        return x=ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,1,1,piles);
        return ans;
    }
};