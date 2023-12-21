class Solution {
public:
    int dp[31][31];
    int f(int i,int j,vector<int>& pref,vector<int>& stones,int k)
    {
        if(i==j)
            return 0;
        auto& x=dp[i][j];
        if(x!=-1)
            return x;
        int ans=1e9;
        for(int idx=i;idx<j;idx+=k-1)
        {
           int tem=f(i,idx,pref,stones,k)+f(idx+1,j,pref,stones,k);
           if(tem!=1e9 && (j-i)%(k-1)==0)
           {
               if(i==0)
                   tem+=pref[j];
               else
                   tem+=pref[j]-pref[i-1];
           }
           ans=min(ans,tem);
        }
        return x=ans;
    }
    int mergeStones(vector<int>& stones, int k) 
    {
       int n=stones.size();
       vector<int> pre(n);
       if((n-1)%(k-1))return -1;
       int ps=0;
       for(int i=0;i<n;i++)
         ps+=stones[i],pre[i]=ps;
       memset(dp,-1,sizeof(dp));
       int ans=f(0,n-1,pre,stones,k);
       ans=(ans==1e9)?-1:ans;
       return ans;
    }
};