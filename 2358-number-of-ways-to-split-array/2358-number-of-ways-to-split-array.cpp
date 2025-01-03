class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;  // Use long long to prevent overflow
        for (int num : nums) {
            totalSum += num;
        }

        long long prefixSum = 0;
        int validSplits = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            prefixSum += nums[i];
            long long suffixSum = totalSum - prefixSum;
            if (prefixSum >= suffixSum) {
                ++validSplits;
            }
        }

        return validSplits;
    }
};
