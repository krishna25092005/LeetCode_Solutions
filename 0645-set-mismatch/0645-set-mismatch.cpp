class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        int duplicate = -1, missing = -1;

        // Count the frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Identify the duplicate and missing numbers
        for (int i = 1; i <= n; ++i) {
            if (freq[i] == 2) {
                duplicate = i;
            } else if (freq[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};