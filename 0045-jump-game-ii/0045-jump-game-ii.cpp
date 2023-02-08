class Solution {
public:
    int jump(vector<int>& nums) 
    {  int curr=0,maxi=0;
     int cnt=0;
     for(int i=0;i<nums.size();i++)
     {
         maxi=max(maxi,nums[i]+i);
         if(i==curr && i!=nums.size()-1)
         {
             curr=maxi;
             cnt++;
         }
     }
       return cnt; 
    }
};