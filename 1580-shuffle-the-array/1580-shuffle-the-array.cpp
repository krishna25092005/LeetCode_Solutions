class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        // Iterate through both parts of the array simultaneously
        for (int i = 0; i < n; i++) {
            result.push_back(nums[i]);     // Add x[i]
            result.push_back(nums[i + n]); // Add y[i]
        }
        return result;
    }
};
