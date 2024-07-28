class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int rowSize = mat.size();
        int colSize = mat[0].size();
        int sumFirst = 0;
        int sumSecond = 0;
        
        for (int i = 0; i < rowSize; ++i) {
            sumFirst += mat[i][i]; // Primary diagonal
        }
        
        for (int i = 0; i < rowSize; ++i) {
            sumSecond += mat[i][rowSize - i - 1]; // Secondary diagonal
        }
        
        // If the matrix size is odd, subtract the middle element once
        if (rowSize % 2 == 1) {
            sumSecond -= mat[rowSize / 2][rowSize / 2];
        }
        
        int totalSum = sumFirst + sumSecond;
        return totalSum;
    }
};
