class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[1]==b[1])
            return a[0]<b[0];
        else
            return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
          sort(intervals.begin(),intervals.end(),cmp); 
          int cnt=0;
          int curr=intervals[0][1];
          for(int i=1;i<intervals.size();i++)
          {
              if(intervals[i][0]>=curr)
              {
                  curr=intervals[i][1];
              }
              else
                  cnt++;
          }
        return cnt;
    }
};