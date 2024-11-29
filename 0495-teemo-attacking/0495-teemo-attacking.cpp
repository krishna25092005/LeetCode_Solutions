class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;  // No attacks
        
        int totalTime = 0;
        for (int i = 0; i < timeSeries.size() - 1; ++i) {
            // Calculate the overlap or non-overlap duration
            totalTime += min(timeSeries[i + 1] - timeSeries[i], duration);
        }
        
        // Add the duration of the last attack
        totalTime += duration;
        return totalTime;
    }
};
