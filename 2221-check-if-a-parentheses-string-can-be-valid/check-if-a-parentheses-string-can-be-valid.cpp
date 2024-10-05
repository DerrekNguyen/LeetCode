class Solution {
public:
   bool canBeValid(string s, string locked) {
      if (locked.length() % 2 != 0) return false;

      int n = locked.size();
      int left = 0, open = 0;

      for (int i = 0; i < n; ++i) {
        if (s[i] == '(') left++;
        else if (locked[i] == '0') open++;
        else {
            if (left > 0) --left;
            else if (open > 0) --open;
            else return false;
        }
      }

    int right = 0;
    open = 0;

      for (int i = n - 1; i >= 0; i--) {
        if (s[i] == ')') right++;
        else if (locked[i] == '0') open++;
        else {
            if (right > 0) --right;
            else if (open > 0) --open;
            else return false;
        }
      }

    return true;
   }
};