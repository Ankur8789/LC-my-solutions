class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
       int ans = INT_MIN;
       queue<int> q;
       multiset<int>  ms;
        q.push(0);
        ms.insert(nums[0]);
       int n = nums.size();
       vector<int> maxi(n);
       maxi[0] = nums[0];
       for(int i = 1 ; i < n; i++)
       {
           while(q.size() > 0 && i - q.front() > k)
           {
               ms.erase(ms.find(maxi[q.front()]));
               q.pop();
           }
           maxi[i] = nums[i] + *ms.rbegin();
           ms.insert(maxi[i]);
           q.push(i);
       }
       return maxi[n-1];
    }
};