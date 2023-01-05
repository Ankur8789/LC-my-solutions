class Solution {
public:
    static bool cmp(vector<int>&a ,vector<int>& b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& v)
    {
        sort(v.begin(),v.end(),cmp);
        int x=v[0][1],cnt=1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i][0]>x)
            {
                cnt++;
                x=v[i][1];
            }
        }
        return cnt;
    }
};