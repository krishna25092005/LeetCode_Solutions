class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Create sets to track seen numbers for rows, columns, and sub-boxes
        vector<unordered_set<char>> rows(9), cols(9), subBoxes(9);

        // Traverse the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];

                // Skip empty cells
                if (num == '.') continue;

                // Determine the index for the sub-box
                int subBoxIndex = (i / 3) * 3 + (j / 3);

                // Check for conflicts
                if (rows[i].count(num) || cols[j].count(num) || subBoxes[subBoxIndex].count(num)) {
                    return false;
                }

                // Add the number to the corresponding row, column, and sub-box
                rows[i].insert(num);
                cols[j].insert(num);
                subBoxes[subBoxIndex].insert(num);
            }
        }

        return true; // No conflicts found
    }
};
