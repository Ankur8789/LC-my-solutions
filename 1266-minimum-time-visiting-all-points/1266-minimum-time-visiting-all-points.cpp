class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
       int ans=0;
       for(int i=1;i<points.size();i++)
       {
           int lx=points[i-1][0];
           int ly=points[i-1][1];
           int cx=points[i][0];
           int cy=points[i][1];
           int diffx=abs(lx-cx);
           int diffy=abs(ly-cy);
           ans+=min(diffx,diffy)+abs(diffx-diffy);
       }
      return ans;
    }
};