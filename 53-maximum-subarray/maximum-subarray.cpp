class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0];
        int maxSub = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if ((maxSub + nums[i]) < nums[i]) maxSub = nums[i];
            else maxSub = (maxSub + nums[i]);
            if (result < maxSub) result = maxSub;
        }
        return result;
    }
};