class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (const auto& num : nums) {
            if (freq.find(num) != freq.end()) {
                freq[num]++;
            } else
                freq[num] = 1;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& item : freq) {
            buckets[item.second].push_back(item.first);
        }

        vector<int> result;
        int i = buckets.size() - 1;
        while (k > 0 && i >= 0) {
            if (!buckets[i].empty()) {
                for (const auto& item : buckets[i]) {
                    result.push_back(item);
                    k--;
                }
            }
            i--;
        }

        return result;
    }
};