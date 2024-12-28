class Solution {
public:
    int numTrees(int n) {
        // Dynamic programming array to store the number of unique BSTs for each i
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case: 1 empty tree
        dp[1] = 1; // Base case: 1 tree with 1 node

        // Calculate number of unique BSTs for each i from 2 to n
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
