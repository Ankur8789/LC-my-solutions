class Solution {
public:
    bool isReachable(int tx, int ty)
    {
       if(tx==1 && ty==1)
           return true;
        int xgcd=__gcd(tx,ty);
        int cc=0;
        for(int i=0;i<32;i++)
        {
            if((xgcd>>i)&1)
                cc++;
        }
        if(cc==1)
            return true;
        else
            return false;
    }
};