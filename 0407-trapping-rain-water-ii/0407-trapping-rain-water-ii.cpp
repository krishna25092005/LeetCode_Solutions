class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        // Push all boundary cells into the priority queue
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n - 1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }
        
        // Directions for 4 possible movements
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;
        
        while (!pq.empty()) {
            auto cell = pq.top(); pq.pop();
            int height = cell.first;
            int x = cell.second.first, y = cell.second.second;
            
            for (auto dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }
        
        return waterTrapped;
    }
};
