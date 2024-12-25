class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int evenCount = 0, oddCount = 0;
        
        for (int pos : position) {
            if (pos % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
        
        // Minimum cost is the size of the smaller group (even or odd)
        return min(evenCount, oddCount);
    }
};
