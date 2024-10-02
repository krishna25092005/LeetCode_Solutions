class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        std::rotate(nums.begin(), nums.begin() + n - k, nums.end());
    }
};