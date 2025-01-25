class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; ++i) {
            numsWithIndex.emplace_back(nums[i], i);
        }
        
        sort(numsWithIndex.begin(), numsWithIndex.end());
        
        vector<vector<int>> groups;
        for (int i = 0; i < n; ) {
            vector<int> group;
            group.push_back(numsWithIndex[i].second);
            int j = i + 1;
            while (j < n && numsWithIndex[j].first - numsWithIndex[j-1].first <= limit) {
                group.push_back(numsWithIndex[j].second);
                j++;
            }
            groups.push_back(group);
            i = j;
        }
        
        vector<int> result(n);
        for (const auto& group : groups) {
            vector<int> sortedGroup = group;
            sort(sortedGroup.begin(), sortedGroup.end());
            for (int i = 0; i < group.size(); ++i) {
                result[sortedGroup[i]] = nums[group[i]];
            }
        }
        
        return result;
    }
};