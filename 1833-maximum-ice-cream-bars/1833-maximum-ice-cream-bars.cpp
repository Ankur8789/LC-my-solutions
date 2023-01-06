class Solution {
public:
    typedef long long ll;
    int maxIceCream(vector<int>& costs, int coins) 
    {
        sort(costs.begin(),costs.end());
        int cc=0;
        for(int i=0;i<costs.size();i++)
        {
            if(costs[i]<=coins)
            {
                cc++;
                coins-=costs[i];
            }
        }
        return cc;
        
    }
};