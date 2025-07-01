class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 10001);
        int n = coins.size();
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = coins[i - 1]; j <= amount; ++j) {
                int notTake = dp[j];
                int take = 1 + dp[j - coins[i - 1]];
                dp[j] = min(notTake, take);
            }
        }

        if (dp[amount] < 10001) return dp[amount];
        return -1;
    }
};