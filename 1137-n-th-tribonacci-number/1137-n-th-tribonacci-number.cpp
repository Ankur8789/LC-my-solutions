class Solution {
public:
   int t[50];
    int tri(int n)
    {
        if(n==0)
              return 0;
        if(n==1 || n==2)
            return 1;
        if(t[n]!=-1)
            return t[n];
        else
            return t[n]=tri(n-1)+tri(n-2)+tri(n-3);
    }
    int tribonacci(int n) 
    {
         memset(t,-1,sizeof(t)); 
        int ans=tri(n);
        return ans;
    }
};