class Solution {
public:
   void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;  // Handle cases where k > n

    // Helper function to reverse a subarray
    auto reverse = [&](int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            ++start;
            --end;
        }
    };

    // Step 1: Reverse the entire array
    reverse(0, n - 1);

    // Step 2: Reverse the first k elements
    reverse(0, k - 1);

    // Step 3: Reverse the rest
    reverse(k, n - 1);
}
};