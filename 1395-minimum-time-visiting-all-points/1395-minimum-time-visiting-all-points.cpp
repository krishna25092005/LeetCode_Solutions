class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime = 0;

        for (int i = 1; i < points.size(); i++) {
            // Current and next point
            int x1 = points[i - 1][0], y1 = points[i - 1][1];
            int x2 = points[i][0], y2 = points[i][1];

            // Add time to move between the two points
            totalTime += max(abs(x2 - x1), abs(y2 - y1));
        }

        return totalTime;
    }
};
