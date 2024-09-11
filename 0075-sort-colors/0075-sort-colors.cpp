class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount =0;
        int onesCount = 0;
        int twoCount = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) zeroCount++;
            if(nums[i]==1) onesCount++;
            else twoCount++;
        }
        fill(nums.begin(), nums.begin() + zeroCount, 0);
fill(nums.begin() + zeroCount, nums.begin() + zeroCount + onesCount, 1); // Fixed range
fill(nums.begin() + zeroCount + onesCount, nums.end(), 2);

    }
};