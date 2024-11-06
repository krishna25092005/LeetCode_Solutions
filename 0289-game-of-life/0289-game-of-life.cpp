class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ans = 0;
                if (i - 1 >= 0 && j - 1 >= 0)
                    ans += board[i - 1][j - 1];
                if (i - 1 >= 0)
                    ans += board[i - 1][j];
                if (i - 1 >= 0 && j + 1 < n)
                    ans += board[i - 1][j + 1];
                if (j - 1 >= 0)
                    ans += board[i][j - 1];
                if (j + 1 < n)
                    ans += board[i][j + 1];
                if (i + 1 < m && j - 1 >= 0)
                    ans += board[i + 1][j - 1];
                if (i + 1 < m)
                    ans += board[i + 1][j];
                if (i + 1 < m && j + 1 < n)
                    ans += board[i + 1][j + 1];
                if (board[i][j] == 1)
                {
                    if (ans < 2)
                        v.push_back({i, j});
                    else if (ans > 3)
                        v.push_back({i, j});
                }
                else
                {
                    if (ans == 3)
                        v.push_back({i, j});
                }
            }
        }
        for (auto it : v)
        {
            board[it.first][it.second] ^= 1;
        }
    }
};