class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
{
    int m = isWater.size();
    int n = isWater[0].size();
    vector<vector<int>> height(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    // Initialize the queue with all water cells and set their height to 0
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (isWater[i][j] == 1)
            {
                height[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Directions for moving north, east, south, and west
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Perform BFS to assign heights
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1)
            {
                height[nx][ny] = height[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    return height;
}
};