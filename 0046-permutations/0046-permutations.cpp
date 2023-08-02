class Solution {
public:
    vector<vector<int>> ans;
    void f(vector<int>& temp,vector<int>& vis,vector<int>& nums)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                temp.push_back(nums[i]);
                f(temp,vis,nums);
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> temp;
        vector<int> vis(nums.size());
        f(temp,vis,nums);
        return ans;
    }
};