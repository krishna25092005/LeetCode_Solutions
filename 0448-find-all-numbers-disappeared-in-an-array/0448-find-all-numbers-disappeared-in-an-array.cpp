class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        
        // Mark the numbers that are found by negating the values at their corresponding indices
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;  // Get the index corresponding to the value
            if (nums[index] > 0) {
                nums[index] = -nums[index];  // Negate the value at that index
            }
        }
        
        // Collect all indices where the value is still positive (those numbers are missing)
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);  // i + 1 is the missing number
            }
        }
        
        return result;
    }
};
