class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        multiset<int> ms;
        int i=0,j=0,n=nums.size();
        vector<int> ans;
        while(j<n)
        {
            ms.insert(nums[j]);
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                ans.push_back(*ms.rbegin());
                // auto it=ms.end();
                // it--;
                ms.erase(ms.find(nums[i]));
                i++;
                j++;
            }
        }
        return ans;
    }
};