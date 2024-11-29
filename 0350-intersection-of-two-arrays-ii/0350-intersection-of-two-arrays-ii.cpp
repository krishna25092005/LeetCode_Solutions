class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> result;
        
        // Count the frequency of each number in nums1
        for (int num : nums1) {
            count[num]++;
        }
        
        // Iterate through nums2 and find common elements
        for (int num : nums2) {
            if (count[num] > 0) {  // If the number is found in nums1
                result.push_back(num);
                count[num]--;  // Decrease the frequency count
            }
        }
        
        return result;
    }
};
