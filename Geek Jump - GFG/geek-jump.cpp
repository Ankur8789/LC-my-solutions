//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[100001];
    int f(int i,vector<int>&height,int n)
    {
        if(i==n-1)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=1e9;
        ans=min(ans,abs(height[i]-height[i+1])+f(i+1,height,n));
        if(i+2<n)
        ans=min(ans,abs(height[i]-height[i+2])+f(i+2,height,n));
        return dp[i]=ans;
        
    }
    int minimumEnergy(vector<int>& height, int n)
    {
        // Code here
        memset(dp,-1,sizeof(dp));
        int ans=f(0,height,n);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends