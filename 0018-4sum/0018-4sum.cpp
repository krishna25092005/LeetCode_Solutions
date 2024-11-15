class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;  // Skip duplicates

        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;  // Skip duplicates

            int left = j + 1, right = n - 1;
            long long remainingTarget = (long long)target - nums[i] - nums[j];

            while (left < right) {
                long long sum = nums[left] + nums[right];
                if (sum == remainingTarget) {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    ++left;
                    --right;
                } else if (sum < remainingTarget) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }

    return result;
}

};