class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) 
    {
       int mask=0;
       vector<int> fre(32,0);
       int ans=1e9;
       int n=nums.size();
       int i=0,j=0;
       while(j<n){
           int val=nums[j];
           for(int idx=0;idx<32;idx++){
               if((val>>idx)&1)
                   fre[idx]++,mask|=(1<<idx);
           }
           while(j>=i && mask>=k){
               for(int idx=0;idx<32;idx++){
                   if((nums[i]>>idx)&1)
                       fre[idx]--;
               }
               for(int idx=0;idx<32;idx++){
                   if(fre[idx]==0 && ((mask>>idx)&1))
                       mask^=(1<<idx);
               }
               ans=min(ans,j-i+1);
               i++;
           }
           j++;
       }
        if(ans==1e9)
            ans=-1;
        return ans;
    }
};