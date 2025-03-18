class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, bitMask = 0, maxLen = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            // If adding nums[r] causes conflict, move left pointer
            while ((bitMask & nums[r]) != 0) {
                bitMask ^= nums[l]; // Remove nums[l] from the bitMask
                l++; // Move left pointer
            }

            // Include nums[r] in the window
            bitMask |= nums[r];

            // Update the maximum length
            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};
