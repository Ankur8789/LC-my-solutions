class Solution {
public:
    const int mod=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req)
    {
        vector<int> log(nums.size()+1);
        for(auto t: req)
        {
            int a=t[0];
            int b=t[1];
            log[a]++;
            log[b+1]--;
        }
        int ps=0;
        vector<int> pref(nums.size());
        // int ps=0;
        for(int i=0;i<nums.size();i++)
        {
            ps+=log[i];
            pref[i]=ps;
            // cout<<ps<<" ";
        }
        vector<vector<int>> vp;
        for(int i=0;i<nums.size();i++)
        {
            vp.push_back({pref[i],i});
        }
        sort(vp.begin(),vp.end());
        reverse(vp.begin(),vp.end());
        vector<int> newar(nums.size());
        priority_queue<int> pq;
        for(auto t: nums)
            pq.push(t);
        for(auto t: vp)
        {
            newar[t[1]]=pq.top();
            pq.pop();
        }
        vector<int> prefix(nums.size());
        int sm=0;
        for(int i=0;i<nums.size();i++)
        {
           sm+=newar[i];
           prefix[i]=sm;
        }
        int ans=0;
        for(auto t: req)
        {
            int a=t[0];
            int b=t[1];
            if(a==0)
                ans+=prefix[b];
            else
                ans+=prefix[b]-prefix[a-1];
            ans%=mod;
        }
       
        return ans;
        
    }
};