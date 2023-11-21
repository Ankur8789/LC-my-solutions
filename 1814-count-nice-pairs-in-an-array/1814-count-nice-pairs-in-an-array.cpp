class Solution {
public:
    const int mod=1e9+7;
    int countNicePairs(vector<int>& nums) 
    {
       long long ans=0;
       map<int,int> mp;
       for(auto t: nums)
       {
           string s=to_string(t);
           reverse(s.begin(),s.end());
           int val=t-stoi(s);
           ans+=mp[val];
           ans%=mod;
           mp[val]++;
       }
       return ans;
    }
};