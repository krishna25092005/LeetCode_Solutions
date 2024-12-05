class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If there are no intervals, return an empty vector
        if (intervals.empty()) return {};

        // Sort intervals by the start time
        sort(intervals.begin(), intervals.end());

        // Initialize the result vector
        vector<vector<int>> result;

        // Start by adding the first interval to the result
        result.push_back(intervals[0]);

        // Traverse the intervals
        for (int i = 1; i < intervals.size(); i++) {
            // Check if the current interval overlaps with the last added interval
            if (intervals[i][0] <= result.back()[1]) {
                // If they overlap, merge the intervals by updating the end of the last interval
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // If they don't overlap, add the current interval to the result
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
