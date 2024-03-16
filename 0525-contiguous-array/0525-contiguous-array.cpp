class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
       map<int,int> mp;
       mp[0]=-1;
       int cnt=0;
       int res=0;
       for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==1)
               cnt++;
           else
               cnt--;
           if(mp.find(cnt)!=mp.end())
           {
              res=max(res,i-mp[cnt]);
           }
           else
               mp[cnt]=i;
       }
       return res;
    }
};