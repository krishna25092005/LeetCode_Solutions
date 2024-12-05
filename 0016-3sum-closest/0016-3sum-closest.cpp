class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        int closestSum = INT_MAX / 2;   // Initialize closest sum with a large value

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;           // Start pointer
            int right = nums.size() - 1; // End pointer

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right]; // Calculate triplet sum
                
                // Update the closest sum if needed
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                // Move pointers based on comparison
                if (currentSum < target) {
                    left++; // Need a larger sum
                } else if (currentSum > target) {
                    right--; // Need a smaller sum
                } else {
                    return currentSum; // Exact match found
                }
            }
        }

        return closestSum;
    }
};
