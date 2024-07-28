class Solution {
public:
    // Brute Force Approach -> Time Complexity : O(nlogn)
    int sortingMethod(vector<int>&nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==i) continue;
            else return i;
        }
        return nums.size();
    }

    // Optimized Approach -> Time Complexity : O(n)
    int xorr(vector<int>&nums) {
        int ans=0;
        // Step-1 XOR all values of an array
        for(int i=0;i<nums.size();i++) {
            ans ^= nums[i];
        }

        // Step-2 XOR all range items [0,n]
        for(int i=0;i<=nums.size();i++) {
            ans ^= i;
        }
        return ans;
    }
    
    int missingNumber(vector<int>& nums) {
        // return sortingMethod(nums);
        return xorr(nums);
    }
};
