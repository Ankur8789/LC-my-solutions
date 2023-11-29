class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int cc=0;
        while(n)
        {
            n=n&(n-1);
            cc++;
        }
        return cc;
    }
};