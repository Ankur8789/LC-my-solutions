//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {

  public:
  typedef long long ll;
    ll f(ll i,ll last,vector<int>& A,vector<vector<ll>>& dp)
    {
        if(i==A.size())
        return 0;
        if(dp[i][last]!=-1)
        return dp[i][last];
        if(last)
        return dp[i][last]=max(A[i]+f(i+1,1,A,dp),f(i+1,0,A,dp));
        else
        return dp[i][last]=A[i]+f(i+1,1,A,dp);
    }
    long long findMaxSubsetSum(int N, vector<int> &A) 
    {
        vector<vector<ll>> dp(N+1,vector<ll>(2,-1));
        ll ans=f(0,1,A,dp);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends