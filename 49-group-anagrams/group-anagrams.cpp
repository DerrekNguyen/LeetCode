class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;

        for (auto& s : strs) {
            array<int, 26> freqMap = {0};
            for (char c : s) {
                freqMap[c - 'a']++;
            }

            string key = "";
            for (int i = 0; i < 26; ++i) {
                key = key + (char)(i + (int)'a') + to_string(freqMap[i]);
            }

            hashmap[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto& p : hashmap) {
            result.push_back(p.second);
        }

        return result;
    }
};