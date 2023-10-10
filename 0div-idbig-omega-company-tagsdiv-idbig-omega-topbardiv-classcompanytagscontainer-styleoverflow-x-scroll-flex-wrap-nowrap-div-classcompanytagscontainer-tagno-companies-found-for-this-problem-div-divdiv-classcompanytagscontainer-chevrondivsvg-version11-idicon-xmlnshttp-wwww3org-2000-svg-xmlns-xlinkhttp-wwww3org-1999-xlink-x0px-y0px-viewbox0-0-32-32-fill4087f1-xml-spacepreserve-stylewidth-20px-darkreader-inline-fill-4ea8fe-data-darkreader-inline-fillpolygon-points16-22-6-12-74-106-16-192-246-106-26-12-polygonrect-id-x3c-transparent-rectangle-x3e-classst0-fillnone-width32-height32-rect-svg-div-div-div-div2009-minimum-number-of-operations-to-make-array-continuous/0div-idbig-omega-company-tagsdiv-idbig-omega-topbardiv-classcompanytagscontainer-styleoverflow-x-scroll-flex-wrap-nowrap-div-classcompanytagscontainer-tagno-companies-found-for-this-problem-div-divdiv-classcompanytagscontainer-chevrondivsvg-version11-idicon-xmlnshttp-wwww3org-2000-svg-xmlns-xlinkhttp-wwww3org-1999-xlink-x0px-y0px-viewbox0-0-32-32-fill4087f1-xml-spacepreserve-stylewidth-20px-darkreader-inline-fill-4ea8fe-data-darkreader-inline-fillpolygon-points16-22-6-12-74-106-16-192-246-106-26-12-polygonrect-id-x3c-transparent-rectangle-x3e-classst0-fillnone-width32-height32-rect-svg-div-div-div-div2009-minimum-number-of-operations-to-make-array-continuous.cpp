class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        set<int>set;
        for(int x:nums)set.insert(x);
        vector<int>arr;
        for(auto x:set)arr.push_back(x);
        int n = nums.size();
        int dup = n- arr.size();
        int ans = INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            int maxElementOnRight = arr[i]+n-1; 
            int index = upper_bound(begin(arr),end(arr),maxElementOnRight)-arr.begin();
            int numOfOperation = arr.size()-index+i;
            ans = min(ans,numOfOperation);
        }
        return ans+dup ;

    }
};