class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> vec=nums;
        sort(vec.begin(),vec.end());
        int idx=-1,jdx=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=vec[i])
            {
                if(idx==-1)
                    idx=i;
                jdx=i;
            }
        }
        if(idx!=-1)
        return jdx-idx+1;
        else
            return 0;

    }
};