class Solution {
public:

    // Brute Force Approach -> Time Complexity : O(n^2)
    int bruteForce(vector<int>&nums) {
        int n= nums.size();
        for(int i=0;i<n;i++) {
            bool isRepeated = false;
        for(int j=i+1;j<n;j++) {
            if(nums[i]==nums[j]) {
                isRepeated = true;
                return nums[i];
            }
        }
        }
        return -1;
    }

    // First Optimized Approach -> Time Complexity : O(n)
    int HashingOrHashSetApproach(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return num;
            }
            seen.insert(num);
        }
        return -1;
    }

    // Second Optimized Approach
    // Floyd's Tortoise and Hare Algorithm -> Time Complexity : O(n)
    int FloydTortoiseAndHareAlgo(vector<int>nums) {
        int tortoise = nums[0];
        int hare = nums[0];
        
        // Phase 1: Find the intersection point of the two runners.
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        
        // Phase 2: Find the entrance to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        // The duplicate number is found.
        return hare;
    }

    int findDuplicate(vector<int>& nums) {
    // return bruteForce(nums);
    // return HashingOrHashSetApproach(nums);
    return FloydTortoiseAndHareAlgo(nums);
    }
};
