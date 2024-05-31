class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
       int pxor=0;
       for(auto x: nums)
           pxor^=x;
       // a^b
       int rem=-1;
       for(int i=31;i>=0;i--)
       {
           if((pxor>>i)&1)
           {
               rem=i;
               break;
           }
       }
       int x=0;
       for(auto t: nums)
       {
           if((t>>rem)&1)
               x^=t;
       }
       int y=pxor^x;
       return {x,y};
    }
};