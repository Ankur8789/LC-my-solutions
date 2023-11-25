class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
         vector<int> ans;
         int n=nums.size();
         vector<int> pref(n),suff(n);
         pref[0]=nums[0];
         suff[n-1]=nums[n-1];
         for(int i=1;i<n;i++)pref[i]+=pref[i-1]+nums[i];
         // cout<<endl;
         for(int i=n-2;i>=0;i--)suff[i]+=suff[i+1]+nums[i];
         // for(int i=0;i<n;i++)cout<<pref[i]<<" "<<suff[i]<<endl;
         for(int i=0;i<n;i++)
         {
             int total=0;
             if(i-1>=0)
                 total+=(i*nums[i]-pref[i-1]);
             if(i+1<n)
                 total+=(suff[i+1]-(n-i-1)*nums[i]);
             ans.push_back(total);
         }
        return ans;
    }
};