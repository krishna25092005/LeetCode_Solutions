class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        // Count frequencies of each element
        for (int num : nums) {
            freqMap[num]++;
        }

        int maxLength = 0;
        // Iterate through the map
        for (auto& [key, value] : freqMap) {
            if (freqMap.find(key + 1) != freqMap.end()) {
                // Calculate the length of harmonious subsequence
                maxLength = max(maxLength, value + freqMap[key + 1]);
            }
        }
        return maxLength;
    }
};