class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> countMap;
        
        // Step 1: Count the frequency of each card number
        for (int card : deck) {
            countMap[card]++;
        }

        // Step 2: Find the GCD of all frequencies
        int gcdValue = 0;
        for (auto& entry : countMap) {
            gcdValue = gcd(gcdValue, entry.second);
        }

        // Step 3: Return true if GCD is greater than 1, otherwise false
        return gcdValue > 1;
    }
};