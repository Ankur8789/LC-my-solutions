class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=1;i<n;i++){
            if((nums[i]&1) == (nums[i-1]&1))
                res[i]=1;
            else
                res[i]=0;
        }
        for(int i=1;i<n;i++){
            res[i]+=res[i-1];
        }
        vector<bool> ans;
        for(auto x: queries){
            int a=x[0],b=x[1];
            if(a==b){
                ans.push_back(true);
                continue;
            }
            int val;
            if(a==0)
                val=res[b];
            else
                val=res[b]-res[a];
            if(val)
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};