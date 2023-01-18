class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int total=0;
        int curr1=0,curr2=0;
        int mx=INT_MIN,mn=INT_MAX;
           
        for(auto it : nums)
        {
            total+=it;
            curr1+=it;
            mx=max(mx,curr1);
            if(curr1<0) curr1=0;
            
            curr2+=it;
            mn=min(curr2,mn);
            if(curr2>0) curr2=0;
        }
        
        
        if(total==mn) return mx;       
        return max(mx,total-mn);   
    }
};