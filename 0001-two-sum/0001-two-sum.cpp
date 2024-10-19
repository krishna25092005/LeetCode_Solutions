class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash_map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (hash_map.find(complement) != hash_map.end()) {
            return {hash_map[complement], i};  // Return the indices
        }
        hash_map[nums[i]] = i;  // Store the number with its index
    }
    return {};
}

};