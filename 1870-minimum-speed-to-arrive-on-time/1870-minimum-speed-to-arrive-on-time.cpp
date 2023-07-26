class Solution {
public:
    int ceill(int up, int down)
    {
        int res = up / down;
        if (up % down != 0)
            res++;
        return res;
    }
    bool check(int mid,vector<int>& dist,double hour)
    {
        double currt=0;
        for(int i=0;i<dist.size();i++)
        {
            if(i!=dist.size()-1)
                currt+=ceill(dist[i],mid);
            else
                currt+=double(dist[i])/double(mid);
        }
        // cout<<currt<<endl;
        return currt<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) 
    {
        int ans=-1;
        int l=1,r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,dist,hour))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        // cout<<check(3,dist,hour)<<endl;
        return ans;
    }
};