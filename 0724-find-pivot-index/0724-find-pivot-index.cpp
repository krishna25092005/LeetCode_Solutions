class Solution {
public:

    // Brute Force Approach {Time Complexity : O(n^2)}
    int BruteForce(vector<int>&nums) {
        int leftSum=0;
        int rightSum=0;
    for(int i=0;i<nums.size();i++) {

        // Find leftSum excluding current index
        for(int j=0;j<i;j++) {
            leftSum += nums[j];
        }

        // Find rightSum excluding current index
        for(int j=i+1;j<nums.size();j++) {
            rightSum += nums[j];
        }
    if(leftSum==rightSum) return i;
        }
    return -1;
    }

// Prefix Sum - Optimized Approach  {Time Complexity : O(n)}
    int PrefixSum(vector<int>&nums) {
    vector<int>leftSum(nums.size(),0);
    vector<int>rightSum(nums.size(),0);
    for(int i=1;i<nums.size();i++) {
        leftSum[i] = leftSum[i-1] + nums[i-1];
    }

    for(int i=nums.size()-2;i>=0;i--) {
        rightSum[i] = rightSum[i+1] + nums[i+1];
    }

    for(int i=0;i<nums.size();i++) {
        if(leftSum[i]==rightSum[i]) return i;
    }
    return -1;
    }

int pivotIndex(vector<int>& nums) {

// return BruteForce(nums);
return PrefixSum(nums);

}
};