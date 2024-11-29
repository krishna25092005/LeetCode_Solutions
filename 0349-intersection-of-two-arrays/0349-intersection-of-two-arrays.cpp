class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());  // Convert nums1 to a set for uniqueness
        unordered_set<int> result;
        
        // Iterate through nums2 and check if the element exists in set1
        for (int num : nums2) {
            if (set1.count(num)) {  // If num is in set1, add to result
                result.insert(num);
            }
        }
        
        // Convert the result set to a vector and return
        return vector<int>(result.begin(), result.end());
    }
};
