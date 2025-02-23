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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postIndex;
        for (int i = 0; i < postorder.size(); i++)
            postIndex[postorder[i]] = i;  // Store indices of postorder elements
        
        int preIndex = 0;
        return buildTree(preorder, postorder, preIndex, 0, postorder.size() - 1, postIndex);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int& preIndex, int left, int right, unordered_map<int, int>& postIndex) {
        if (preIndex >= preorder.size() || left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIndex++]); // Root from preorder

        if (left == right || preIndex >= preorder.size()) return root; // Single node case

        // Find left child in postorder
        int leftChildIndex = postIndex[preorder[preIndex]];

        // Recursively build left and right subtrees
        root->left = buildTree(preorder, postorder, preIndex, left, leftChildIndex, postIndex);
        root->right = buildTree(preorder, postorder, preIndex, leftChildIndex + 1, right - 1, postIndex);

        return root;
    }
};