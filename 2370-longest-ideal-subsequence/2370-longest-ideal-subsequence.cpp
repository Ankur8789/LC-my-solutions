class Solution {
public:
    int dp[100001][27];
    int f(int i, int pre, int k, string& s)
    {
        if(i == s.size())
            return 0;
        auto & x = dp[i][pre + 1];
        if(x != -1)
            return x;
        int ans = 0;
        if(pre == -1 || abs(s[i] - 'a' - pre) <= k)
        {
           ans = max( ans , 1 + f(i+1 , s[i] - 'a' , k ,s));
           ans = max( ans , f( i+1 , pre , k ,s));
        }
        else
        {
            ans = max( ans , f( i+1 , pre , k ,s));
        }
        return x = ans;
    }
    int longestIdealString(string s, int k) 
    {
       memset(dp , -1 , sizeof(dp));
       int ans = f(0 , -1 , k ,s);
       return ans;
    }
};