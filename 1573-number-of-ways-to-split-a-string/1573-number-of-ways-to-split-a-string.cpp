class Solution {
public:
    const int mod=1e9+7;
    int numWays(string s) 
    {
        int ans=0;
        int n=s.size();
        vector<int> cnt(n);
        if(s[0]=='1')
            cnt[0]=1;
        for(int i=1;i<n;i++)
            cnt[i]+=((s[i]=='1')?1:0)+cnt[i-1];
        for(int i=0;i<n-2;i++)
        {
            // cout<<cnt[i]<<" ";
            // yaha tak pehla partition
            if(cnt[n-1]!=3*cnt[i])
                continue;
            int req=2*cnt[i];
            int found=false;
            int l=i+1,r=n-2;
            int ansl=l;
            // left most
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(cnt[mid]>=req)
                {
                    if(cnt[mid]==req)
                    found=true;
                    ansl=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            // cout<<ansl<<endl;
            if(!found)
                continue;
            // right most
            l=i+1,r=n-2;
            int ansr=l;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(cnt[mid]<=req)
                {
                    ansr=mid;
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            int range=(ansr-ansl+1);
            range%=mod;
            // cout<<range<<endl;
            ans+=range;
            ans%=mod;
        }
        return ans;
        
    }
};