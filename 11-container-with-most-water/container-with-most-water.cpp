class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int result = 0;
        while (l < r) {
            result = max(result, ((r - l) * (min(height[l], height[r]))));
            if (height[l] > height[r]) r--;
            else l++;
        }
        return result;
    }
};