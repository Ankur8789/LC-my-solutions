class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        vector<pair<int,int>> vp;
        vector<int> pref(300000+5,0);
        for(int i=0;i<nums.size();i++)
        {
            
            pref[nums[i]-k+100000]++;
            pref[nums[i]+k+1+100000]--;
        }
       
        int res=0;
        int ps=0;
        for(int i=0;i<300000+5;i++)
        {
            ps+=pref[i];
            res=max(res,ps);
            pref[i]=ps;
        }
        return res;
        
    }
};