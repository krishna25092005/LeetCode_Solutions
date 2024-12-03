class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // Initialize minRow and minCol to the size of the matrix
        int minRow = m, minCol = n;

        // Update minRow and minCol based on each operation
        for (const auto& op : ops) {
            minRow = min(minRow, op[0]);
            minCol = min(minCol, op[1]);
        }

        // The number of maximum integers is the area of the smallest rectangle
        return minRow * minCol;
    }
};