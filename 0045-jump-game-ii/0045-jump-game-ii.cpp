class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0; // Already at the last index

        int jumps = 0, currentEnd = 0, farthest = 0;

        // Iterate through the array
        for (int i = 0; i < n - 1; i++) {
            // Update the farthest point reachable
            farthest = max(farthest, i + nums[i]);

            // If we reach the end of the current jump range
            if (i == currentEnd) {
                jumps++;        // Increment the jump counter
                currentEnd = farthest; // Update the end of the current jump range

                // If the currentEnd reaches or exceeds the last index
                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};
