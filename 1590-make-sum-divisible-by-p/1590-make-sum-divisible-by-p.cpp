class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        long long sm = 0;
        for (auto t : nums)
            sm += t;
        if (sm % p == 0)
            return 0;
        unordered_map<long long, long long> m;

        long long ans = INT_MAX;
        long long sum = 0;
        long long rem=sm%p;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            long long k = sum % p;
            if (k == rem)
                ans = min(ans, (i + 1)*1LL);
            if (m.find(k - rem) != m.end())
                ans = min(ans, i - m[k - rem]);
            if (m.find(k - rem + p) != m.end())
                ans = min(ans, i - m[p + k - rem]);
            m[k] = i;
        }
        if (ans >= nums.size())
            return -1;

        return ans;
    }
};