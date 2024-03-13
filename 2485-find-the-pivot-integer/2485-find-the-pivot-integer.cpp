class Solution {
public:
    int pivotInteger(int n) 
    {
        int sum=n*(n+1)/2;
        int sumx=0;
        for(int i=1;i<=n;i++)
        {
            sumx+=i;
            
            if(sumx==sum)
                return i;
            sum-=i;
        }
        return -1;
    }
};