class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Step 1: Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Step 2: Iterate through the sorted array and check triplets
        for (int i = 0; i < nums.size() - 2; ++i) {
            // Check if nums[i], nums[i+1], nums[i+2] form a valid triangle
            if (nums[i] < nums[i+1] + nums[i+2]) {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }
        
        // Step 3: If no valid triangle is found, return 0
        return 0;
    }
};