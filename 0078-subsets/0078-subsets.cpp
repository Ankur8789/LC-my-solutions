class Solution {
public:
    void subsets(vector<int> &v,vector<vector<int>> &subs,int i,vector<int> &nums)
    {
        if(i==nums.size())
        {
            subs.push_back(v);
        }
        else
        {
            v.push_back(nums[i]);
            subsets(v,subs,i+1,nums);
            v.pop_back();
            subsets(v,subs,i+1,nums);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> v;
        vector<vector<int>> subs;
        sort(nums.begin(),nums.end());
        subsets(v,subs,0,nums);
        return subs;
        
        
    }
};