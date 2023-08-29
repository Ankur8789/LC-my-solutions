class Solution {
public:
    int minOperations(int n) 
    {
        vector<int> res;
        for(int i=1;i<=n;i++)
            res.push_back(2*i+1);
        int ans=0;
        if(n&1)
        {
            int tem=res[n/2];
            for(auto t: res)
                ans+=abs(tem-t);
            ans/=2;
        }
        else
        {
            int tem=res[n/2]+res[n/2 -1];
            tem/=2;
            for(auto t: res)
                ans+=abs(tem-t);
            ans/=2;
        }
        return ans;
    }
};