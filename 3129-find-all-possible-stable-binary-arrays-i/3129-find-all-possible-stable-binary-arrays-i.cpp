#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
class Solution {
public:
    const int mod = 1e9+ 7;
    int dp[201][201][2][201];
    int f(int zr,int on,int limit,int pre,int cnt)
    {
        if(cnt > limit)
            return 0;
        if(zr<0 || on<0)
            return 0;
        if(zr == 0 && on == 0)
            return 1;
        auto&x = dp[zr][on][pre][cnt];
        if(x!=-1)
            return x;
        int ans = 0;
        if(pre == 1)
        {
            ans+=f(zr,on-1,limit,1,cnt+1);
            ans%=mod;
            ans+=f(zr-1,on,limit,0,1);
            ans%=mod;
        }
        else
        {
            ans+=f(zr,on-1,limit,1,1);
            ans%=mod;
            ans+=f(zr-1,on,limit,0,cnt+1);
            ans%=mod;  
        }
        return x=ans;
        
    }
    int numberOfStableArrays(int zero, int one, int limit) 
    {
        fastio();
        int ans = 0;
        for(int i = 0;i < zero+1;i++)
        {
            for(int j = 0 ;j <= one ;j++)
            {
                for(int k = 0 ; k < 2; k++)
                {
                    for(int l = 0;l<=limit;l++)
                        dp[i][j][k][l] = -1;
                }
            }
        }
        ans += f(zero-1,one,limit,0,1);
        ans%=mod;
        ans += f(zero,one-1,limit,1,1);
        ans%=mod;
        return ans;
    }
};