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
    void solution(TreeNode* node, string& bin, int& result) {
        bin = bin + std::to_string(node->val);
        if (node->left) {
            solution(node->left, bin, result);
            bin.erase(bin.size() - 1);
        }
        if (node->right) {
            solution(node->right, bin, result);
            bin.erase(bin.size() - 1);
        }
        if (node->left == nullptr && node->right == nullptr)
            result += stoi(bin, nullptr, 2);
    }

    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        string bin = "";
        solution(root, bin, result);
        return result;
    }
};