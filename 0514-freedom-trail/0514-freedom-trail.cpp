class Solution {
public:
    int dp[101][101];
    int f(int i,int curr,string& ring,string& key,map<char,vector<int>>& mp)
    {
        if(curr==key.size())
            return 0;
        auto&x =dp[i][curr];
        if(x!=-1)
            return x;
        int ans=1e9;
        vector<int> temp = mp[key[curr]];
        for(int idx=0;idx<temp.size();idx++)
        {
            int val1 = abs(i - temp[idx]);
            int val2 = ring.size() - val1;
            ans = min(ans,val1+f(temp[idx],curr+1,ring,key,mp));
            ans = min(ans,val2+f(temp[idx],curr+1,ring,key,mp)); 
        }
        return  x=ans;
    }
    int findRotateSteps(string ring, string key) 
    {
        map<char,vector<int>> mp;
        for(int i=0;i<ring.size();i++)
        mp[ring[i]].push_back(i);
        int ans = 1e9;
        vector<int> temp = mp[key[0]];
        memset(dp,-1,sizeof(dp));
        for(int idx=0;idx<temp.size();idx++)
        {
            int val1 = abs(0 - temp[idx]);
            int val2 = ring.size() - val1;
            ans = min(ans,val1+f(temp[idx],0+1,ring,key,mp));
            ans = min(ans,val2+f(temp[idx],0+1,ring,key,mp)); 
        }
        return ans + key.size();
    }
};