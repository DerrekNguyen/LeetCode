class Solution {
public:
   void solution(int n, int l, int r, string str, vector<string>& result) {
      if (l == n && r == n) {
         result.push_back(str);
         return;
      }

      if (l < n) {
         str = str + '(';
         solution(n, l + 1, r, str, result);
         str.erase(str.size() - 1);
      }

      if (r < l && l <= n) {
         str = str + ')';
         solution(n, l, r + 1, str, result);
         str.erase(str.size() - 1);
      }

      return;
   }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solution(n, 0, 0, "", result);
        return result;
    }
};