class Solution {
public:
    bool isPowerOfTwo(int n)
    {
       if(n==1)
           return 1;
       if(n==0 || n&1)
           return 0;
       return isPowerOfTwo(n/2);
    }
};