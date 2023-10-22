class Solution {
public:
    int maximumScore(vector<int>& nums, int k) 
    {
        int n=nums.size() ;
        vector<int> pref(n),suff(n);
        pref[k]=nums[k];
        // suff[n-1]=nums[n-1];
        for(int i=k-1;i>=0;i--)
            pref[i]=min(pref[i+1],nums[i]);
        suff[k]=nums[k];
        for(int i=k+1;i<n;i++)
            suff[i]=min(suff[i-1],nums[i]);
        int i=0,j=n-1;
        int ans=INT_MIN;
        while(i<=j)
        {
           ans=max(ans,(j-i+1)*(min({pref[i],suff[j],nums[k]})));
           if(pref[i]<suff[j])
               i++;
           else
               j--;
        }
        return ans;
        
    }
};