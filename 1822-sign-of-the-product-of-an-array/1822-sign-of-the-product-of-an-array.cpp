class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
       int zr=0,neg=0;
       for(auto t: nums)
       {
           if(t==0)
               zr++;
           else if(t<0)
               neg++;
       }
        if(zr>0)
            return 0;
        if(neg&1)
            return -1;
        return 1;
    }
};