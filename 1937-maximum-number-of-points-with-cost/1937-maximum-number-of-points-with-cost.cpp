class Solution {
public:
    typedef long long ll;
    long long maxPoints(vector<vector<int>>& mat) 
    {
        ll n=mat.size();
        ll m=mat[0].size();
        vector<vector<ll>>dp(n,vector<ll>(m,0));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=mat[0][i];
        }
        for(int i=1;i<n;i++)
        {
            vector<ll>left(m,0),right(m,0);
            vector<ll>val=dp[i-1];
            left[0]=val[0];
            right[m-1]=val[m-1];
            for(ll j=1;j<m;j++)
            {
                left[j]=max(left[j-1]-1,val[j]);
            }
            for(ll j=m-2;j>=0;j--)
            {
                right[j]=max(right[j+1]-1,val[j]);
            }
            for(ll j=0;j<m;j++)
            {
                dp[i][j]=mat[i][j]+max(left[j],right[j]);
            }
        }
        return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};