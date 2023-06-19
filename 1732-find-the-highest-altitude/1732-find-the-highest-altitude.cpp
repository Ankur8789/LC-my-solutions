class Solution {
public:
    int largestAltitude(vector<int>& gain) 
    {
        int ps=0,ans=0;
        for(auto t: gain)
        {
            ps+=t;
            ans=max(ans,ps);
        }
        return ans;
    }
};