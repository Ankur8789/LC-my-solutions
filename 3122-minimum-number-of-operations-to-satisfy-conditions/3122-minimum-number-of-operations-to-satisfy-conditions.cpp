#define mmt(a, v) memset(a, v, sizeof(a));
class Solution {
public:
    int dp[1001][11];
    int f(int i,int pre , map<int,map<int,int>>& mp , int n , int m)
    {
        if(i == n)
            return 0;
        auto & x = dp[i][pre+1];
        if( x != -1)
            return x;
        int ans = 1e9;
        for(int idx = 0 ;idx < 10 ;idx++)
        {
            if(idx == pre)continue;
            ans = min(ans , m - mp[i][idx] + f(i+1, idx , mp, n, m));
        }
        return x = ans;
    }
    int minimumOperations(vector<vector<int>>& grid) 
    {
       map<int, map<int,int>> mp;
       int m = grid.size();
       int n = grid[0].size();
       for(int j = 0 ;j < n ;j++)
       {
           for(int i = 0;i < m ; i++)
           {
               mp[j][grid[i][j]]+=1;
           }
       }
       mmt(dp , -1);
       int ans = f(0 , -1 , mp , n , m);
       return ans;
       
    }
};