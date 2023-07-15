//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[100001];
    int f(int idx,vector<int>& nums,int k)
    {
        if(idx==nums.size())
        return 0;
        if(dp[idx]!=-1)
        return dp[idx];
        int ans=1e9;
        int ps=0;
        int cc=0;
        for(int i=idx;i<nums.size();i++)
        {
           ps+=nums[i];
           cc++;
           if(ps+cc-1>k)
           break;
           if(i==nums.size()-1)
           ans=min(ans,0);
           else
           ans=min(ans,(k-(ps+cc-1))*(k-(ps+cc-1))+f(i+1,nums,k));
        }
        return dp[idx]=ans;
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        int ans=f(0,nums,k);
        return ans;
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends