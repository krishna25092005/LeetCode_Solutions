class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // Get the dimensions of the input matrix
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Create a new matrix with flipped dimensions
        vector<vector<int>> result(cols, vector<int>(rows));
        
        // Populate the transposed matrix
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[j][i] = matrix[i][j];
            }
        }
        
        return result;
    }
};
