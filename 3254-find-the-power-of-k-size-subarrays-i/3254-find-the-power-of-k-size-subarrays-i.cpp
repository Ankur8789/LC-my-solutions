class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pref(n),ans;
        pref[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)
                pref[i]=pref[i-1]+1;
            else
                pref[i]=1;
        }
        int i=0,j=0;
        while(j<n){
            if(j-i+1<k)
                j++;
            else if(j-i+1==k){
                int rem=pref[j];
                if(i>0 && rem>k)
                    rem-=pref[i-1];
                if(rem==k){
                    ans.push_back(nums[j]);
                }
                else{
                    ans.push_back(-1);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};