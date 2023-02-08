#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
class Solution {
public:
    
   int dp[1001];
    int f(vector<int> &arr,int i,int d,int n)
    {
        if(dp[i] != -1) 
            return dp[i];
        int ans = 0;
        for(int j=i+1;j<=min(n-1,i+d);j++)
        {
            if(arr[i]>arr[j])
                ans=max(ans,f(arr,j,d,n));
            else
                break;
        }
        for(int j=i-1;j>=max(i-d,0);j--)
        {
            if(arr[i] > arr[j])
               ans=max(ans,f(arr,j,d,n));
            else
                break;
        }
        return dp[i]=ans+1;
        
    }
    int maxJumps(vector<int>& arr, int d)
    {   
        fastio();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            ans = max(ans,f(arr,i,d,n));
        }
        return ans;
    }
};