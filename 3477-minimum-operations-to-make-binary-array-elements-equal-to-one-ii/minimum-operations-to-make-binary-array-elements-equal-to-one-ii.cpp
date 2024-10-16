class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i, result, check;

        i = n - 1;
        check = 0;
        result = 0;
        
        while (i >= 0) {
            if (nums[i] == 1) {
                check = 1;
                while (i >= 0 && nums[i] == 1) i--;
            }
            else {
                result += (check + 1);
                check = 0;
                while (i >= 0 && nums[i] == 0) i--;
            }
        }
        return result;
    }
};