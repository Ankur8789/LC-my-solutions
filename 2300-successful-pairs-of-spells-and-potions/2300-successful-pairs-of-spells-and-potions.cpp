class Solution {
public:
    typedef long long ll;
    vector<int> successfulPairs(vector<int>& sp, vector<int>& pt, long long ss) 
    {
        vector<int> ans;
        sort(pt.begin(),pt.end());
        for(int idx=0;idx<sp.size();idx++)
        {
            ll l=0,r=pt.size()-1;
            ll aa=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(1LL*pt[mid]*sp[idx]>=ss)
                {
                    aa=mid;
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            if(aa==-1)
             ans.push_back(0);
            else
            ans.push_back(pt.size()-aa);
        }
        return ans;
        
    }
};