class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min = nums[0];
        int result = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < min) min = nums[i];
            else if (result < (nums[i] - min))
                result = (nums[i] - min);
        }
        if (result > 0) return result;
        return -1;
    }
};