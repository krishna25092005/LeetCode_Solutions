class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mergedMap;

        for (auto& num : nums1) {
            mergedMap[num[0]] += num[1];
        }

        for (auto& num : nums2) {
            mergedMap[num[0]] += num[1];
        }

        vector<vector<int>> result;
        for (auto& entry : mergedMap) {
            result.push_back({entry.first, entry.second});
        }

        return result;
    }
};
