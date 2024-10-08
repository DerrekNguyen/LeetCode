/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solution(TreeNode* node, int sum, int& result) {
        int temp = 2*sum + node->val;
        if (node->left) solution(node->left, temp, result);
        if (node->right) solution(node->right, temp, result);
        if (node->left == nullptr && node->right == nullptr) result += temp;
    }

    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        solution(root, 0, result);
        return result;
    }
};