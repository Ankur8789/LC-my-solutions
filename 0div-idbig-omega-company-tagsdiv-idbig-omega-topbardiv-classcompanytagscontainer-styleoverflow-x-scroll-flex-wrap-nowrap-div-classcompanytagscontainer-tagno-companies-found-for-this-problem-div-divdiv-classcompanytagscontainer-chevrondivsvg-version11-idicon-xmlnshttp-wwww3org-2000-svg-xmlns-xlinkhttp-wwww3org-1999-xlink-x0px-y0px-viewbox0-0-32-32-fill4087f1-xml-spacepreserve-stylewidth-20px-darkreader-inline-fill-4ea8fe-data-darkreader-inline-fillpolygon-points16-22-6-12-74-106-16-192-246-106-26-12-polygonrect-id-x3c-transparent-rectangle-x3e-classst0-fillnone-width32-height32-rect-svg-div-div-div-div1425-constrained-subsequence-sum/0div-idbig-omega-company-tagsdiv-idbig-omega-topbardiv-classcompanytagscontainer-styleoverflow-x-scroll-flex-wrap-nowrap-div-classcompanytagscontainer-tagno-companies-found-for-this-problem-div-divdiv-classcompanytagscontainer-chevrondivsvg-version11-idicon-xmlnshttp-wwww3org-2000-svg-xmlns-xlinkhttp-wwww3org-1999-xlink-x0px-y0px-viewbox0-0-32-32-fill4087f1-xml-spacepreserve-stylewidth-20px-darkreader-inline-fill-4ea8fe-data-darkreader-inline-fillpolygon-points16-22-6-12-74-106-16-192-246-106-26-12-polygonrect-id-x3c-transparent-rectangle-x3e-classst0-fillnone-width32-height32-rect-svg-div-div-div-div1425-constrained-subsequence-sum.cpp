class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) 
    {
       priority_queue<pair<int,int>> pq;
        pq.push({nums[0],0});
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            while(pq.size()>0 && i-pq.top().second>k)
                pq.pop();
            int curr=0;
            curr+=max(nums[i],nums[i]+pq.top().first);
            res=max(res,curr);
            pq.push({curr,i});
           
        }
        return res;
    }
};