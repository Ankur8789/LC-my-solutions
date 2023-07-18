class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
       int res=0;
       int cnt=0;
       for(auto t: nums)
       {
           if(t==1)
               cnt++;
           else
           {
               res=max(res,cnt);
               cnt=0;
           }
       }
        if(cnt)
            res=max(res,cnt);
        return res;
    }
};