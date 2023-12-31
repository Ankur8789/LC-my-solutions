class Solution {
public:
    bool check(int mid,vector<vector<int>>& pre)
    {
        for(auto t:pre)
        {
            int cc=0;
            for(auto x:t)
            {
                if(x>=mid)
                {
                    cc+=x-(mid-1);
                }
            }
            if(cc>=3)
            {
                return true;
            }
        }
        return false;
    }
    int maximumLength(string s) 
    {
        vector<vector<int>> pre(26);
        int prev=s[0];
        int cnt=1;
        for(int i=1;i<s.size();++i)
        {
            if(prev==s[i])
                cnt++;
            else
            {
                pre[prev-'a'].push_back(cnt);
                cnt=1;
                prev=s[i];
            }
        }
        pre[prev-'a'].push_back(cnt);
        int l=1,r=s.size()-2;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,pre))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};