class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>&b)
    {
        if(a[1]==b[1])
            return a[0]>b[0];
        else
            return a[1]<b[1];
        
    }
    int maxEnvelopes(vector<vector<int>>& env) 
    {
        sort(env.begin(),env.end(),cmp);
        int ans=1;
        vector<int> val;
        val.push_back(env[0][0]);
        for(int i=1;i<env.size();i++)
        {
            int n=val.size();
            if(env[i][0]>val[n-1])
            {
                // ans++;
                val.push_back(env[i][0]);
            }
            else
            {
                int l=0,r=val.size()-1;
                int t=0;
                while(l<=r)
                {
                   int mid=(l+r)/2;
                   if(val[mid]>=env[i][0])
                   {
                       t=mid;
                       r=mid-1;
                   }
                    else
                       l=mid+1; 
                }
                val[t]=env[i][0];
            }
        }
            
        
        return val.size();
    }
};