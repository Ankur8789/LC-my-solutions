//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[100001][5];
    int f(int i,int n,int pre,vector<vector<int>>& points)
    {
        if(i==points.size())
        return 0;
        if(dp[i][pre]!=-1)
        return dp[i][pre];
        int ans=INT_MIN;
        if(pre!=1)
        {
           ans=max(ans,points[i][0]+f(i+1,n,1,points)); 
        }
        if(pre!=2)
        {
            ans=max(ans,points[i][1]+f(i+1,n,2,points));
        }
        if(pre!=3)
        {
            ans=max(ans,points[i][2]+f(i+1,n,3,points));
        }
        return  dp[i][pre]=ans;
    }
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,n,0,points);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends