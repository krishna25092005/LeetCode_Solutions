class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = *min_element(nums.begin(), nums.end());
        int maxNum = *max_element(nums.begin(), nums.end());
        
        int difference = maxNum - minNum;
        // If the range can be reduced to 0
        if (difference <= 2 * k) {
            return 0;
        }
        // Otherwise, reduce the range by 2 * k
        return difference - 2 * k;
    }
};
