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

    // Better Approach -> Time Complexity : O(nlogn)
    int binarySearch(vector<int>&nums) {
        sort(nums.begin(),nums.end());

        int s=0;
        int e=nums.size()-1;
        int mid = s+(e-s)/2;
        int ans = -1;
        while(s<=e) {
            int number = nums[mid];
            int index = mid;
            int diff = number - index;
            if(diff==0) {
                // right me jao
                s=mid+1;
            }
            if(diff==1) {
                ans = index;
                // left me jao
                e=mid-1;
            }
            // ye mein bhul jata hu
            mid = s+(e-s)/2;            
        }
        if(ans==-1) {
                return nums.size();
            }
        return ans;
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
        // return xorr(nums);
        return binarySearch(nums);
    }
};