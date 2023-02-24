class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minVal = INT_MAX;
        priority_queue<int> pq;
        for (auto n:nums) {
            if (n & 1) n <<= 1;
            pq.push(n);
            minVal = min(minVal, n);
        }

        int ans = INT_MAX;
        while (true) {
            int maxVal = pq.top();
            pq.pop();
            ans = min(ans, maxVal - minVal);
            if (maxVal & 1) break;
            maxVal >>= 1;
            minVal = min(minVal, maxVal);
            pq.push(maxVal);
        }

        return ans;
    }
};