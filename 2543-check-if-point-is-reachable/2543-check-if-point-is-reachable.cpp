class Solution {
public:
    // this kind of problems require thinking from the back
    bool isReachable(int tx, int ty)
    {
        if(tx==1 || ty==1)
            return true;
        int p=__gcd(tx,ty);
        int cc=0;
        for(int i=0;i<32;i++)
        {
            if((p>>i)&1)
                cc++;
        }
        return cc==1;
    }
};