class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
         map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        int j=0;
        for(auto i:m)
        {
            if(i.second>1)
            {
                nums[j]=i.first;
                j++;
            }
                nums[j]=i.first;
                j++;
            
        }
        return j;
    }
};