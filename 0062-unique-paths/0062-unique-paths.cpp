class Solution {
public:
     int uniquePaths(int m, int n) {
        long long paths = 1;
        int k = min(m - 1, n - 1);
        for (int i = 1; i <= k; ++i) {
            paths = paths * (m + n - 1 - i) / i;
        }
        return (int)paths;
    }
};