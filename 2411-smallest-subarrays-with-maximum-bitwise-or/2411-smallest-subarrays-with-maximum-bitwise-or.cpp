class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
       int n=nums.size();
       vector<vector<int>> pref(n,vector<int>(32,0));
       for(int i=0;i<n;i++){
           int val=nums[i];
           for(int j=0;j<32;j++){
               pref[i][j]+=((val>>j)&1);
           }
           if(i>0){
               for(int j=0;j<32;j++)
                   pref[i][j]+=pref[i-1][j];
           }
       }
       vector<int> res;
       for(int i=0;i<n;i++){
           vector<int> curr=pref[n-1];
           if(i>0){
               for(int j=0;j<32;j++)
                   curr[j]-=pref[i-1][j];
           }
           int l=i,r=n-1;
           int ans=-1;
           while(l<=r){
               int mid=(l+r)/2;
               vector<int> chk=pref[mid];
               if(i>0){
                   for(int j=0;j<32;j++)
                       chk[j]-=pref[i-1][j];
               }
               bool found=true;
               for(int j=0;j<32;j++){
                   if(curr[j]){
                       if(chk[j])continue;
                       else found=false;
                   }
               }
               if(found){
                   ans=mid;
                   r=mid-1;
               }
               else{
                   l=mid+1;
               }
           }
           res.push_back(ans-i+1);
       }
        return res;
        
    }
};