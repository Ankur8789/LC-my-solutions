class Solution {
public:
    #define ld long double
    int reverse(int x) 
    {
        ld res=0;
        while(x)
        {
            int d=x%10;
            res=res*10+d;
            x/=10;
        }
        ld mx=powl(2,31)-1;
        ld mn=powl(-2,31);
        if(res>=mn && res<=mx)
            return res;
        return 0;
            
    }
};