// class Solution {
// public:
// // Brute Force Approach -> Time Complexity : O(n^3)
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end()); // Sort the array to help with duplicate handling
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates

//                 for (int k = j + 1; k < nums.size(); k++) {
//                     if (k > j + 1 && nums[k] == nums[k - 1]) continue; // Skip duplicates

//                     if (nums[i] + nums[j] + nums[k] == 0) {
//                         ans.push_back({nums[i], nums[j], nums[k]});
//                     }
//                 }
//             }
//         }
        
//         return ans;
//     }
// };

// Two Pointer Technique -> Time Complexity : O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort the array
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates
            
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return ans;
    }
};

