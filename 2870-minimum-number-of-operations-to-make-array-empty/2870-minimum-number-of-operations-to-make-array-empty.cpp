class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        map<int,int> mp;
        for(auto t: nums)mp[t]+=1;
        int ans=0;
        for(auto t: mp)
        {
            if(t.second==1)
                return -1;
            if(t.second%3==0)
                ans+=t.second/3;
            else
                ans+=(t.second-1)/3+1;     
        }
        return ans;
    }
};