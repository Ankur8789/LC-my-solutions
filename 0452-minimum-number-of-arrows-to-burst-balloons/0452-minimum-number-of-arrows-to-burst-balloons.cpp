class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end(),cmp);
        for(auto t: points)
        int cc=1;
        int count=0;
        int mn=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=mn)
            {
                continue;
            }
            else
            {
                count++;
                mn=points[i][1];
            }
        }
        return count+1;
    }
};