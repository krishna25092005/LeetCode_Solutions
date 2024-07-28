class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int size = nums.size();
        vector<pair<int, int>> p;

        // Create a vector of pairs (number, original index)
        for (int i = 0; i < size; ++i) {
            p.push_back({nums[i], i});
        }

        // Sort the vector of pairs based on the number values
        sort(p.begin(), p.end());

        int low = 0;
        int high = size - 1;

        while (low < high) {
            int currSum = p[low].first + p[high].first;
            if (currSum == target) {
                ans.push_back(p[low].second);
                ans.push_back(p[high].second);
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
