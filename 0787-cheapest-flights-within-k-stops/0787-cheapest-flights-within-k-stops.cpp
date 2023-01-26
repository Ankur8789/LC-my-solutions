class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
       
        int MAX_VALUE = 100000; vector<int> prices(n, MAX_VALUE); prices[src] = 0;
        
        for (int i = 0; i < k+1; i++) 
        {
            vector<int> tmpPrices = prices;  
            for (const auto& flight: flights) tmpPrices[flight[1]] = min(tmpPrices[flight[1]], flight[2] + prices[flight[0]]); 
            prices = tmpPrices;
        }
        return prices[dst] == MAX_VALUE? -1: prices[dst];
    }
};