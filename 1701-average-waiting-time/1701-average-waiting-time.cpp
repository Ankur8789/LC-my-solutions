class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cus) 
    {
        double currt=0;
        double wait=0;
        for(auto a: cus)
        {
            currt = max(currt, 1.0 * a[0]) + a[1];
            wait += currt - a[0];
        }
        return wait/(double)cus.size();
        
    }
};