class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n, 0), rightMax(n, 0);
        int waterTrapped = 0;

        // Fill leftMax array
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Fill rightMax array
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate the trapped water
        for (int i = 0; i < n; i++) {
            waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
        }

        return waterTrapped;
    }
};
