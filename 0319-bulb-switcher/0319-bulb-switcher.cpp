class Solution {
public:
    int bulbSwitch(int n) 
    {
        int sm=0,cc=0;
        for(int i=1;i<=n;i+=2)
        {
            sm+=i;
            if(sm>n)
                break;
            cc++;
            
        }
        return cc;
    }
};