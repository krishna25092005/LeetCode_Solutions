class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        
        // Map to store the position of each number in the matrix
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pos[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowCount(m, 0), colCount(n, 0);

        for (int i = 0; i < arr.size(); ++i) {
            int num = arr[i];
            auto [r, c] = pos[num];

            // Increment row and column paint count
            rowCount[r]++;
            colCount[c]++;

            // Check if the row or column is fully painted
            if (rowCount[r] == n || colCount[c] == m) {
                return i;
            }
        }

        return -1; // This should never be reached given problem constraints
    }
};