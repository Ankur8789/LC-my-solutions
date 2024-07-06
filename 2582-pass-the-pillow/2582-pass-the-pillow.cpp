class Solution {
public:
    int passThePillow(int n, int time) 
    {
       int x=0;
        for(int i=1;i<=n;i++)
        {
            if(time==x)
                return i;
            x++;
            if(i==n)
            {
                for(int j=n-1;j>=2;j--)
                {
                    if(time==x)
                        return j;
                    x++;
                }
                i=0;
            }
        }
        return 0;
    }
};