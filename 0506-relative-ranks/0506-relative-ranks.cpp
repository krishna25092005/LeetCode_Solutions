class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        // Step 1: Pair scores with indices
        vector<pair<int, int>> scoreWithIndex;
        for (int i = 0; i < n; ++i) {
            scoreWithIndex.push_back({score[i], i});
        }
        
        // Step 2: Sort by scores in descending order
        sort(scoreWithIndex.begin(), scoreWithIndex.end(), greater<pair<int, int>>());
        
        // Step 3: Prepare the ranks
        vector<string> result(n);
        for (int rank = 0; rank < n; ++rank) {
            if (rank == 0) {
                result[scoreWithIndex[rank].second] = "Gold Medal";
            } else if (rank == 1) {
                result[scoreWithIndex[rank].second] = "Silver Medal";
            } else if (rank == 2) {
                result[scoreWithIndex[rank].second] = "Bronze Medal";
            } else {
                result[scoreWithIndex[rank].second] = to_string(rank + 1);
            }
        }
        
        return result;
    }
};
