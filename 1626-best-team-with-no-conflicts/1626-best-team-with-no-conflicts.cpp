class Solution {
public:
    //dp problem
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.second==b.second)
            return a.first<b.first;
        else
            return a.second<b.second;
    }
    // dp starts here
    int dp[1001][1001];
    int f(int i,int pre,vector<pair<int,int>>& v)
    {
        if(i==v.size())
            return 0;
        if(dp[i][pre+1]!=-1)
            return dp[i][pre+1];
        if(pre==-1 || (v[pre].second<v[i].second && v[pre].first<=v[i].first))
            return dp[i][pre+1]=max(v[i].first+f(i+1,i,v),f(i+1,pre,v));
        else if(pre==-1 || (v[pre].second==v[i].second))
            return dp[i][pre+1]=max(v[i].first+f(i+1,i,v),f(i+1,pre,v));
        else
            return dp[i][pre+1]=f(i+1,pre,v);
    }
   
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        int n=ages.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({scores[i],ages[i]});
        sort(v.begin(),v.end(),cmp);
        memset(dp,-1,sizeof(dp));
        int ans=f(0,-1,v);
        return ans;
         
    }
};