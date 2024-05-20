class Solution {
public:
    int ans=0;
    void f(vector<int>& nums,int pxor,int i,int taken)
    {
        if(i==nums.size())
        {
            if(taken)
                ans+=pxor;
            return ;
        }
        f(nums,pxor^nums[i],i+1,taken|1);
        f(nums,pxor,i+1,taken);
    }
    int subsetXORSum(vector<int>& nums) 
    {
       f(nums,0,0,0);
       return ans;
    }
};