class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        multiset<pair<int,int>> ms;
        for(int i=0;i<nums.size();i++)
            ms.insert({nums[i],i});
        while(k--){
            auto x=*ms.begin();
            ms.erase(ms.begin());
            int val=x.first,idx=x.second;
            val*=mul;
            ms.insert({val,idx});
        }
        for(auto x: ms)
            nums[x.second]=x.first;
        return nums;
    }
};