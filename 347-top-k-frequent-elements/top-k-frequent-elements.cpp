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

        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> maxHeap;
        for (const auto& item : freq) {
            maxHeap.push(item);
        }

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().first);
            maxHeap.pop();
        }

        return result;
    }
};