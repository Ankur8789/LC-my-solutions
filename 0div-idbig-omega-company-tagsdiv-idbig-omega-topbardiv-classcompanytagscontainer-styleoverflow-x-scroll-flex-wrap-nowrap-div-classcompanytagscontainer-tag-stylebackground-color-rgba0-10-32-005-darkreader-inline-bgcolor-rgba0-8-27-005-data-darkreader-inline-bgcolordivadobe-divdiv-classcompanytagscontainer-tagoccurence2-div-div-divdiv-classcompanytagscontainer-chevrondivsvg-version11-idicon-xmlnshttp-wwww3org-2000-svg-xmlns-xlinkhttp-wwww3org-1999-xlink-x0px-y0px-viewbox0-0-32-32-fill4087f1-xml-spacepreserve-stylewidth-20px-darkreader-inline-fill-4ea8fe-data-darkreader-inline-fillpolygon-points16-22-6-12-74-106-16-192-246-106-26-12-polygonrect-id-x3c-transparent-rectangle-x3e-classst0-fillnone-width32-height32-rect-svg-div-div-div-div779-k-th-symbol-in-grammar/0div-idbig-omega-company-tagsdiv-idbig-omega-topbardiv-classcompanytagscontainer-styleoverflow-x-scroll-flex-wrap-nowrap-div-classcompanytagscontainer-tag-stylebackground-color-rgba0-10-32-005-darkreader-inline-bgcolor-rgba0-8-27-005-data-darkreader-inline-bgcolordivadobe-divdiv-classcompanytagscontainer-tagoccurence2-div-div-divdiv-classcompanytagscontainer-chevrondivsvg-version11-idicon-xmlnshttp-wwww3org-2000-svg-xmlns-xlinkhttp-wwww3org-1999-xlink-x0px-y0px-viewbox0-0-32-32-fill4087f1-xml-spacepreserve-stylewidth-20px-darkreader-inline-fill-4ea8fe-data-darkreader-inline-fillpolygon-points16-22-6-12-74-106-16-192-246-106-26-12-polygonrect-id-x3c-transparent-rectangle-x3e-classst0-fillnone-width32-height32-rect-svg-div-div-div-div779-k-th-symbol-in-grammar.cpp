class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        int res=0;
        int pre=log2(k);
        while(pow(2,pre)<k)
        {
            k-=pow(2,pre);
            pre=log2(k);
            ++res;
        }
        res+=pre;
        return (res&1);
    }
};