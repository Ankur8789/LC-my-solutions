class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(begin(points),end(points),cmp);
        int mn=points[0][1];
        int cnt=1;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=mn)continue;
            else
            {
                cnt++;
                mn=points[i][1];
            }
        }
        return cnt;
    }
};