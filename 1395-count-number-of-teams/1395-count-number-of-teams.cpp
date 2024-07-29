class Solution {
public:
    int dp[1001][1002][4];
    int f(int i,int last,int idx,vector<int>& v){
        if(idx==3)
            return 1;
        if(i==v.size())
            return 0;
        auto& x=dp[i][last+1][idx];
        if(x!=-1)
            return x;
        int ans=0;
        if(idx==0){
            ans+=f(i+1,i,idx+1,v);
            ans+=f(i+1,last,idx,v);
        }
        else{
            if(v[last]<v[i])
                ans+=f(i+1,i,idx+1,v);
            ans+=f(i+1,last,idx,v);
        }
        return x=ans;
    }
    int numTeams(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,-1,0,v);
        memset(dp,-1,sizeof(dp));
        reverse(begin(v),end(v));
        ans+=f(0,-1,0,v);
        return ans;
    }
};