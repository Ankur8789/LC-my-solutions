class Solution {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        if(left==0)
            return 0;
        for(int i=0;i<32;i++)
        {  if(1<<i < 0)
            break;
            if((1<<i)>left && (1<<i)<=right)
                return 0;
        }
        if(left==right)
            return left;
        long long int ans=left;
        for(unsigned long long int i=left+1;i<=right;i++)
        {  if(i<0)break;
            ans&=i;
            if(ans<0)
                break;
        }
        return ans;
        
    }
};