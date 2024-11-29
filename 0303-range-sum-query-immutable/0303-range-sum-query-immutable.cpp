class NumArray {
public:
    vector<int> prefixSum;

    // Constructor initializes the prefix sum array
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0); // Create a prefix sum array of size n + 1
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i]; // Build prefix sum array
        }
    }
    
    // Function to compute the sum between indices left and right
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};
