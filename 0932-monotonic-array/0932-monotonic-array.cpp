class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true, decreasing = true;
        
        // Check if the array is increasing or decreasing
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                decreasing = false;
            }
            if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
        }
        
        return increasing || decreasing;
    }
};
