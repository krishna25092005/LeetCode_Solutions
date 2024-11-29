class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        // Step 2: Sum up the elements at even indices
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        
        return sum;
    }
};