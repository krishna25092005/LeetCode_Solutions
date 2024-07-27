class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int size = nums.size();
        vector<pair<int, int>> numIndexPairs;

        // Create a vector of pairs (number, original index)
        for (int i = 0; i < size; ++i) {
            numIndexPairs.push_back({nums[i], i});
        }

        // Sort the vector of pairs based on the number values
        sort(numIndexPairs.begin(), numIndexPairs.end());

        int low = 0;
        int high = size - 1;

        while (low < high) {
            int currSum = numIndexPairs[low].first + numIndexPairs[high].first;
            if (currSum == target) {
                ans.push_back(numIndexPairs[low].second);
                ans.push_back(numIndexPairs[high].second);
                return ans;
            } else if (currSum > target) {
                high--;
            } else {
                low++;
            }
        }

        return ans; // return an empty vector if no pair is found
    }
};
