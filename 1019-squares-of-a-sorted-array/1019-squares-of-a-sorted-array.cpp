class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        int left = 0, right = n - 1, index = n - 1;
        
        while (left <= right) {
            // Compare the absolute values of nums[left] and nums[right]
            if (abs(nums[left]) > abs(nums[right])) {
                result[index] = nums[left] * nums[left];
                left++;
            } else {
                result[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }
        
        return result;
    }
};