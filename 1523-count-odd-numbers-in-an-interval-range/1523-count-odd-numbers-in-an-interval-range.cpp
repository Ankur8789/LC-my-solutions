class Solution {
public:
    int countOdds(int low, int high) 
    {
        if(low==high)
        {
            if(low%2!=0)
            {
                return 1;
            }
        }
        if(low%2!=0&&high%2!=0)
        {
            int a=high-low-1;
            a/=2;
            return(a+2);
        }
        if(low%2==0&&high%2==0)
        {
            int a=high-low;
            a/=2;
            return a;
        }
        
            int a=high-low;
            a/=2;
            return (a+1);
        
    }
};