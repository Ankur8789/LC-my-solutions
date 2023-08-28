class Solution {
public:
    typedef long long ll;
    int shortestSubarray(vector<int>& nums, int k)
    {
        deque<pair<ll,ll>> dq;
        ll sum=0;
        ll res=1e9;
        for(ll i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>=k)res=min(res,i+1);
            while(dq.size()>0 && sum-dq.front().first>=k)
            {
                res=min(res,i-dq.front().second);
                dq.pop_front();
            }
            while(dq.size()>0 && dq.back().first>=sum)
            {
                dq.pop_back();
            }
            dq.push_back({sum,i});
        }
        if(res==1e9)
            res=-1;
        return res;
    }
};