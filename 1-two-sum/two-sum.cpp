class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> t;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = t.find(target - nums[i]);
            if (it != t.end())
                return {it->second, i};
            
            t[nums[i]] = i;
        }
        return {};
    }
};