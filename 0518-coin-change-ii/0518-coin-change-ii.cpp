class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> DP(amount + 1, 0);
        DP[0] = 1;
        for(int i = 1; i <= coins.size(); i++) {
            for(int j = 1; j <= amount; j++) {
                if(coins[i - 1] <= j)
                    DP[j] = DP[j] + DP[j - coins[i - 1]];
            }
        }
        return DP[amount];
    }
};