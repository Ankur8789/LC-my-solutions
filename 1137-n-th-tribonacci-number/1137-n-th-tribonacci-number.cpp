class Solution {
public:
    int dp [38];
    int f(int n)
    {
        
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        auto & x = dp[n];
        if(x != -1)
            return x;
        return  x = f(n-1) + f(n-2) + f(n-3);
    }
    int tribonacci(int n) 
    {
       memset(dp , -1 , sizeof(dp));
       int ans = f(n);
       return ans;
    }
};