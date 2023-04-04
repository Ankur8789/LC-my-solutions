class Solution {
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        multiset<int> ms1,ms2;
        for(auto t: nums)
            ms2.insert(t);
        for(int i=0;i<nums.size()-1;i++)
        {
            ms1.insert(nums[i]);
            ms2.erase(ms2.find(nums[i]));
            if(*ms1.rbegin()<=*ms2.begin())
            {
                return i+1;
            }
        }
        return 0;
    }
};