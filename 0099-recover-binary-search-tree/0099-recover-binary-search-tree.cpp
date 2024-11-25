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
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        inorderTraversal(root, first, second, prev);
        if (first && second) {
            swap(first->val, second->val);
        }
    }

private:
    void inorderTraversal(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if (!root) return;
        inorderTraversal(root->left, first, second, prev);
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        inorderTraversal(root->right, first, second, prev);
    }
};