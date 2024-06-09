class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k)
    {
      int cnt=0;
      int sum=0;
      map<int,int> mp;
      mp[0]++;
      for(auto x: nums)
      {
          sum+=x;
          sum%=k;
          if(sum<0)
              sum+=k;
          sum%=k;
          cnt+=mp[sum];
          mp[sum]++;
      }
      return cnt;
    }
};