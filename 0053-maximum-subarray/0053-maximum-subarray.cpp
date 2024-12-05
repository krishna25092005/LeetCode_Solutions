class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // Decide whether to extend the current subarray or start a new one
            currentSum = max(nums[i], currentSum + nums[i]);
            // Update the maximum sum found so far
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
