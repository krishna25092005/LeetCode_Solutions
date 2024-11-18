class Solution
{
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int dist1 = abs(target[0]) + abs(target[1]);

        for (auto ghost : ghosts)
        {
            int dist2 = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (dist2 <= dist1)
            {
                return false;
            }
        }

        return true;
    }
};