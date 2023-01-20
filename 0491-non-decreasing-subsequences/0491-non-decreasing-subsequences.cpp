class Solution {
public:
    void f(int i,int pre,vector<int>& v,vector<vector<int>>& ans,vector<int>& nums)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return ;
        }
        if(pre==-1 || nums[i]>=nums[pre])
        {
          v.push_back(nums[i]);
            f(i+1,i,v,ans,nums);
            v.pop_back();
        }
        f(i+1,pre,v,ans,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        f(0,-1,v,ans,nums);
        set<vector<int>> s;
        for(int i=0;i<ans.size();i++)
            s.insert(ans[i]);
        ans.clear();
        for(auto it=s.begin();it!=s.end();it++)
        {
            auto x=*(it);
            if(x.size()>=2)
                ans.push_back(x);
        }
        return ans;
    }
};