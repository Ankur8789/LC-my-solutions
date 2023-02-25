class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int Min=prices[0]; int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            Min=min(Min,prices[i]);
            profit=max(profit,prices[i]-Min);
        }
        return profit;
    }
};