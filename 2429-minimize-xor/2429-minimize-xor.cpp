class Solution {
public:
    typedef long long ll;
    int ppc(int n)
    {
        int c = 0;
        for (; n; ++c)
        n &= n - 1;
        return c;
     }
    int minimizeXor(int num1, int num2) 
    {
        int bits1=ppc(num1);
        int bits2=ppc(num2);
        cout<<bits1<<" "<<bits2<<endl;
        if(bits1==bits2)
            return num1;
        if(bits1<bits2)
        {  
            for(int i=0;i<32;i++)
            {
                if(bits1==bits2)
                    return num1;
                if(!((num1>>i)&1))
                {
                    num1|=(1<<i);
                    bits1++;
                }
            }
        }
        if(bits1>bits2)
        {  //cout<<1;
            for(int i=0;i<32;i++)
            { // cout<<num1<<endl;
                if(bits1==bits2)
                    return num1;
                if((num1>>i)&1)
                {
                    num1&=~(1<<i);
                    bits1--;
                }
            }
        }
        return 0;
    }
};