class Solution {
public:
    int dp[100001][3];
    int f(int i,vector<vector<int>>& e,int cc){
        if(i==e.size() || cc==2)
            return 0;
        auto& x=dp[i][cc];
        if(x!=-1)
            return x;
        int ans=0;
        ans=max(ans,f(i+1,e,cc));
        int l=i+1,r=e.size()-1,res=e.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(e[mid][0]>e[i][1]){
                res=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        ans=max(ans,e[i][2]+f(res,e,cc+1));
        return x=ans;
    }
    int maxTwoEvents(vector<vector<int>>& e) {
        memset(dp,-1,sizeof(dp));
        sort(begin(e),end(e));
        int n=e.size();
        int ans=f(0,e,0);
        return ans;
    }
};