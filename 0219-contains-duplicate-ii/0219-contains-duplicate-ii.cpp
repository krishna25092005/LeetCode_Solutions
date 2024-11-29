class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // To store the element and its last index
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
                return true; // Found a duplicate within range k
            }
            map[nums[i]] = i; // Update the index of the element
        }
        return false; // No duplicates within range k
    }
};