class Solution {
public:
     int t[10001][501];
     const int M=1e9+7;
    long long f(int i,int steps,int arrlen)
    {
        if(i>=arrlen || i<0)
            return 0;
        if(steps==0 && i==0)
            return 1;
         if(steps==0)
             return 0;
        if(t[i][steps]!=-1)
            return t[i][steps];
        return t[i][steps]=(f(i,steps-1,arrlen)+f(i+1,steps-1,arrlen)+f(i-1,steps-1,arrlen))%M;;
    }
    int numWays(int steps, int arrlen) 
    {  
        memset(t,-1,sizeof(t));
        long long ans=f(0,steps,arrlen);
        return ans;
    }
};