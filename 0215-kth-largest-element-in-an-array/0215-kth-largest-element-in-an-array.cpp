class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
       priority_queue<int> pq;
       for(auto t: nums)
           pq.push(t);
       while(k>1)
       {
           pq.pop();
           k--;
       }
        return pq.top();
    }
};