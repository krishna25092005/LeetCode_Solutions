class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int pos = lower_bound(nums.begin(), nums.end(), 1) - nums.begin();
        int neg = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        return max(neg, n - pos);
    }
};
