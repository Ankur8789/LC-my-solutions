
int ppc(int n){
    int c = 0;
    for (; n; ++c)
        n &= n - 1;
    return c;
}
class Solution {
public:
    bool canSortArray(vector<int>& nums){
        vector<int> ans;
        int pre=-1;
        int i=0;
        int n=nums.size();
        vector<int> tem;
        while(i<n){
            if(pre!=ppc(nums[i])){
                sort(tem.begin(),tem.end());
                for(auto t: tem)
                    ans.push_back(t);
                tem.clear();
                tem.push_back(nums[i]);
                pre=ppc(nums[i]);
                i++;
            }
            else{
                tem.push_back(nums[i]);
                i++;
            }
        }
        if(tem.size()>0){
          sort(tem.begin(),tem.end());
          for(auto t: tem)
            ans.push_back(t);  
        }
        sort(nums.begin(),nums.end());
        return ans==nums;
    }
};