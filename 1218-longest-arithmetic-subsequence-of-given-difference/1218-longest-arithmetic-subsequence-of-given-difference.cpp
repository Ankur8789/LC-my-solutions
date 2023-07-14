class Solution {
public:
    int longestSubsequence(vector<int>& arr, int k) 
    {
        unordered_map<int,int> dp,freq;
        int res=0;
        for(int i=0;i<arr.size();i++)
        {
            if(freq.find(arr[i]-k)!=freq.end())
            {
                dp[arr[i]]=dp[arr[i]-k]+1;
            }
            else
                dp[arr[i]]=1;
            res=max(res,dp[arr[i]]);
            freq[arr[i]]++;
        }
        return res;
    }
};