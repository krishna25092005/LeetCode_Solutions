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
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return construct(nums, 0, nums.size());
    }
private:
    TreeNode *construct(const vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nullptr;

        int maxIndex = max_element(nums.begin() + left, nums.begin() + right) - nums.begin();
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = construct(nums, left, maxIndex);
        root->right = construct(nums, maxIndex + 1, right);

        return root;
    }
};