//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     int dp[101][101];
    int f(int i,int j,int arr[],int N)
    {
        if(i>=j)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        int ans=INT_MAX;
        for(int idx=i;idx<j;idx++)
        {
            ans=min(ans,arr[i-1]*arr[idx]*arr[j]+f(i,idx,arr,N)+f(idx+1,j,arr,N));
        }
        return dp[i][j]=ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        int ans=f(1,N-1,arr,N);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends