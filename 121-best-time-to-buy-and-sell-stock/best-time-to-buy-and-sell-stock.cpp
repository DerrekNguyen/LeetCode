class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int maxDiff = 0;
        for (int i = 1; i < prices.size(); ++i) {
            maxDiff += (prices[i] - prices[i - 1]);
            if (maxDiff < 0) maxDiff = 0;
            if (maxDiff > result) result = maxDiff;
        }
        return result;
    }
};