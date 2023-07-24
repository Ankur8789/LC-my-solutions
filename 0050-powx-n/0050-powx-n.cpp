class Solution {
public:
    double f(double x,int n)
    {
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if(n == -1)
            return 1/x;
        if(n%2 == 0)
            return f(x*x, n/2);
        else
            return f(x, n/abs(n)) * f(x*x, n/2);
    }
    double myPow(double x, int n) 
    {
        double ans=f(x,n);
        return ans;
    }
};