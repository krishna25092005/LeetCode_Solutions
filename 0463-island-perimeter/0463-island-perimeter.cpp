class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) { // Land cell
                    perimeter += 4;
                    
                    // Check the cell to the right
                    if (j + 1 < cols && grid[i][j + 1] == 1) {
                        perimeter -= 2; // Shared edge with the right cell
                    }
                    
                    // Check the cell below
                    if (i + 1 < rows && grid[i + 1][j] == 1) {
                        perimeter -= 2; // Shared edge with the cell below
                    }
                }
            }
        }
        
        return perimeter;
    }
};
