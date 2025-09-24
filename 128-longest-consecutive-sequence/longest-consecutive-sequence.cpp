class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashMap;
        for (const auto& entry: nums)
            hashMap.insert(entry);
        
        int result = 0;
        int tempResult = 0;
        int tempEntry;

        for (const auto& entry : hashMap) {
            if (!hashMap.count(entry - 1)) {
                int tempResult = 1;
                int tempEntry = entry + 1;
                while (hashMap.count(tempEntry)) {
                    tempEntry++;
                    tempResult++;
                }
                result = max(result, tempResult);
            }
        }

        return result;
    }
};