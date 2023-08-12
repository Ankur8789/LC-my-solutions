class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        else
            return a.first<b.first;
    }
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<ranges.size();i++)
        {
            int mn=max(i-ranges[i],0);
            int mx=min(i+ranges[i],n);
            vp.push_back({mn,mx});
            
        }
        sort(vp.begin(),vp.end(),cmp);
        // for(auto t: vp)
        //     cout<<t.first<<" "<<t.second<<endl;
        //usko liye jo sabse dur jayega
        vector<pair<int,int>> req;
        req.push_back(vp[0]);
        int cnt=0;
        int curr=0;
        int i=0;
        while(i<=n)
        {
            int last=curr;
            while(i<=n&&  curr>=vp[i].first)
            {
                last=max(last,vp[i].second);
                i++;
            }
            cnt++;
            if(last==n)
                return cnt;
            if(last==curr)
                return -1;
            curr=last;
        }
      
        return cnt;
    }
};