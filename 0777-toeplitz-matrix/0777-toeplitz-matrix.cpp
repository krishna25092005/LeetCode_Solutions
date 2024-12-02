class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();    // number of rows
        int n = matrix[0].size(); // number of columns
        
        for (int i = 0; i < m - 1; ++i) {     // loop over rows (excluding the last row)
            for (int j = 0; j < n - 1; ++j) { // loop over columns (excluding the last column)
                if (matrix[i][j] != matrix[i+1][j+1]) {
                    return false; // if diagonals don't match, it's not a Toeplitz matrix
                }
            }
        }
        
        return true; // all diagonals are equal
    }
};
