class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        else
            return a[0]<b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& inv) 
    {
       sort(inv.begin(),inv.end(),cmp);
       int cnt=0;
       int pre=inv[0][1];
       int n=inv.size();
       for(int i=1;i<n;i++)
       {
           if(inv[i][1]<=pre)
               cnt++;
           else
           {
               pre=inv[i][1];
           }
       }
       return n-cnt;
    }
};