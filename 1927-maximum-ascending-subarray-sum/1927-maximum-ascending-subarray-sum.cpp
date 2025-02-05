class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0], currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];
            } else {
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i]; // Start a new subarray
            }
        }

        return max(maxSum, currentSum); // Ensure the last subarray is considered
    }
};
