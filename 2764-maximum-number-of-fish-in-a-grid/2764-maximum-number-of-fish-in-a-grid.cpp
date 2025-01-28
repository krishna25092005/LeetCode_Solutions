class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int maxFish = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // DFS
        function<int(int, int)> dfs = [&](int r, int c) {
            if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0 || visited[r][c]) 
                return 0;
            
            visited[r][c] = true;
            int fishCount = grid[r][c];

            for (auto [dr, dc] : directions) {
                fishCount += dfs(r + dr, c + dc);
            }

            return fishCount;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    maxFish = max(maxFish, dfs(i, j));
                }
            }
        }

        return maxFish;
    }
};