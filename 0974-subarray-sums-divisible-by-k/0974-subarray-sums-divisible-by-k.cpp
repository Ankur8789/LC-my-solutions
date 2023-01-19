class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int cnt=0,sum=0;
        unordered_map<int,int> mp;
        for(auto t: nums)
        {
            sum+=t;
            int rem=sum%k;
            if(rem==0)
                cnt++;
            if(rem<0)
                rem+=k;
            if(mp.find(rem)!=mp.end())
            {
                cnt+=mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};