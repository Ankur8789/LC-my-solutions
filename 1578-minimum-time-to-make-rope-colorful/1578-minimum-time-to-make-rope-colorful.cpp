class Solution {
public:
    int minCost(string colors, vector<int>& need) 
    {
       int ans=0;
       int n=colors.size();
       for(int i=1;i<n;i++)
       {
           if(colors[i]==colors[i-1])
           {
               ans+=min(need[i],need[i-1]);
               need[i]=max(need[i],need[i-1]);
           }
       }
      return ans;
    }
};