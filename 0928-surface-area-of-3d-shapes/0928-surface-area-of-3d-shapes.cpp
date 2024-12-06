class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    // Add the surface area of all cubes in this cell
                    totalArea += grid[i][j] * 6;
                    // Subtract the faces hidden by stacking in the same cell
                    totalArea -= (grid[i][j] - 1) * 2;
                }

                // Subtract faces glued horizontally with the next cell in the same row
                if (j + 1 < n) {
                    totalArea -= 2 * min(grid[i][j], grid[i][j + 1]);
                }

                // Subtract faces glued vertically with the next cell in the same column
                if (i + 1 < n) {
                    totalArea -= 2 * min(grid[i][j], grid[i + 1][j]);
                }
            }
        }

        return totalArea;
    }
};