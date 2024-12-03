class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // Use a set to find the unique types of candies
        unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());
        
        // Calculate the maximum number of candies Alice can eat
        int maxCandies = candyType.size() / 2;
        
        // Return the smaller value between unique types and maxCandies
        return min((int)uniqueCandies.size(), maxCandies);
    }
};