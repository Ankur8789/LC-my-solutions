class Solution {
public:
    typedef long long ll;
    int minimizeArrayValue(vector<int>& nums) 
    {
        ll ps=0;
        ll mx=0;
        for(int i=0;i<nums.size();i++)
        {
            ps+=nums[i];
            ll val=(ps+i)/(i+1);
            mx=max(mx,val);
        }
        return mx;
    }
};