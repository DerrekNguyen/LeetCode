class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; ++i) sum += nums[i];

        if (sum % 2 != 0) return false;
        int target = sum/2;

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j - nums[i - 1] >= 0) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][target];
    }
};