class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int i = 0; i < nums.size(); ++i)
            total += nums[i];
        
        int P = total + target;
        if (P % 2 != 0) return 0;
        if (P < 0) return 0;

        P /= 2;

        vector<int> dp(P + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = P; j >= nums[i - 1]; --j) {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
        }

        return dp[P];
    }
};