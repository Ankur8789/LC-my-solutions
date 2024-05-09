class Solution {
public:
    typedef long long ll;
    long long maximumHappinessSum(vector<int>& h, int k) 
    {
      sort(begin(h),end(h));
      reverse(begin(h),end(h));
      ll sum=0;
      ll curr=0;
      for(ll i=0;i<k;i++)
          sum+=max(h[i]-curr++,0LL);
      return sum;
    }
};