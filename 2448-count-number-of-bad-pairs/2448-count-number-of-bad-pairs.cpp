class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, long long> freq;
        long long totalPairs = (long long)nums.size() * (nums.size() - 1) / 2;
        long long goodPairs = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            goodPairs += freq[i - nums[i]];
            freq[i - nums[i]]++;
        }
        
        return totalPairs - goodPairs;
    }
};