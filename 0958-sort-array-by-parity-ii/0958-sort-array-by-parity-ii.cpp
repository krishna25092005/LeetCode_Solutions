class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int evenIdx = 0, oddIdx = 1;

        while (evenIdx < n && oddIdx < n) {
            // If even index is correct, move to the next even index
            if (nums[evenIdx] % 2 == 0) {
                evenIdx += 2;
            }
            // If odd index is correct, move to the next odd index
            else if (nums[oddIdx] % 2 == 1) {
                oddIdx += 2;
            }
            // Swap mismatched elements
            else {
                swap(nums[evenIdx], nums[oddIdx]);
            }
        }

        return nums;
    }
};
