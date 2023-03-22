//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int dp[1001][1002];
	int f(int i,int pre,int arr[],int n)
	{
	    if(i==n)
	    return 0;
	    if(dp[i][pre+1]!=-1)
	    return dp[i][pre+1];
	    if(pre==-1 || arr[i]>arr[pre])
	    {
	        return dp[i][pre+1]=max(arr[i]+f(i+1,i,arr,n),f(i+1,pre,arr,n));
	    }
	    else
	    {
	        return dp[i][pre+1]=f(i+1,pre,arr,n);
	    }
	}
	int maxSumIS(int arr[], int n)  
	{   memset(dp,-1,sizeof(dp));
	    int ans=f(0,-1,arr,n);
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends