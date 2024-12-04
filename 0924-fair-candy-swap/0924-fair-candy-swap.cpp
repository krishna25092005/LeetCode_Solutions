class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        
        // The difference we need to balance
        int diff = (sumA - sumB) / 2;
        
        // Create a set of Bob's candy sizes for fast lookup
        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        
        // Iterate over Alice's candy sizes
        for (int x : aliceSizes) {
            int y = x - diff;
            if (bobSet.count(y)) {
                return {x, y};  // Found the pair (x, y) to swap
            }
        }
        
        return {};  // This will never be reached since we are guaranteed a solution
    }
};
