class Solution {
public:
    int dp[200001];
    int f(int i,int turn,vector<int>& pref,vector<int>& stones)
    {
       if(i==pref.size()-1)
           return pref[i];
       auto& x=dp[i];
       if(x!=INT_MIN)
           return x;
       int ans=INT_MIN;
       ans=max(ans,f(i+1,turn,pref,stones));
       if(i>0)
       ans=max(ans,pref[i]-f(i+1,turn,pref,stones));
       return x=ans;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int> pref(n);
        pref[0]=stones[0];
        for(int i=1;i<n;i++)
            pref[i]+=pref[i-1]+stones[i];
        for(int i=0;i<=n;i++)
        {
                dp[i]=INT_MIN;
        }
        int ans=f(0,1,pref,stones);
        return ans;
    }
};