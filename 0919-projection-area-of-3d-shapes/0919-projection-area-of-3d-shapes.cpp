class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int topView = 0, frontView = 0, sideView = 0;
        
        for (int i = 0; i < n; ++i) {
            int maxRow = 0, maxCol = 0;
            for (int j = 0; j < n; ++j) {
                // Top view: Count non-zero cells
                if (grid[i][j] > 0) {
                    topView++;
                }
                // Front view: Max value in the row
                maxRow = max(maxRow, grid[i][j]);
                // Side view: Max value in the column
                maxCol = max(maxCol, grid[j][i]);
            }
            frontView += maxRow;
            sideView += maxCol;
        }
        
        return topView + frontView + sideView;
    }
};