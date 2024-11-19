class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long maxSum = 0;
        long long currentSum = 0;
        unordered_map<int, int> mp;

        for (int i = 0, j = 0; i < nums.size(); ++i)
        {
            currentSum += nums[i];
            mp[nums[i]]++;

            while (mp.size() > k || mp[nums[i]] > 1)
            {
                currentSum -= nums[j];
                mp[nums[j]]--;
                if (mp[nums[j]] == 0)
                {
                    mp.erase(nums[j]);
                }
                ++j;
            }

            if (mp.size() == k)
            {
                maxSum = max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
};
