//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //typedef long long ll;
    int dp[51];
    bool ispow(int val)
    {
        if(val==0)
        return false;
       if(val==1)
       return true;
       else if(val%5!=0)
       return false;
       return ispow(val/5);
    }
    int f(int i,string& s)
    {
        if(i==s.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int ans=1e5;
        int val=0;
        int cnt=0;
        for(int idx=i;idx<s.size();idx++)
        {
            if(s[idx]=='1')
           { val+=powl(2,cnt);
            if(ispow(val) && val>0)
            ans=min(ans,1+f(idx+1,s));}
            cnt++;
        }
        return dp[i]=ans;
    }
    int cuts(string s)
    {
        reverse(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        int ans=f(0,s);
        // int ans=-1;
        if(ans>=1e5)
        ans=-1;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends