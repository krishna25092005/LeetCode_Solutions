#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();          // Number of rows in original matrix
        int n = mat[0].size();       // Number of columns in original matrix
        
        // If reshape is not possible, return the original matrix
        if (m * n != r * c) {
            return mat;
        }
        
        // Create the reshaped matrix
        vector<vector<int>> reshaped(r, vector<int>(c));
        
        // Traverse the original matrix and fill the reshaped matrix
        for (int i = 0; i < m * n; ++i) {
            reshaped[i / c][i % c] = mat[i / n][i % n];
        }
        
        return reshaped;
    }
};
