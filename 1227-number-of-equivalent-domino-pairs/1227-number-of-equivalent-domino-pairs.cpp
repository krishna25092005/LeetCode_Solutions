class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // Hash map to count normalized domino frequencies
        unordered_map<int, int> freq;

        // Normalize and count frequencies
        for (const auto& domino : dominoes) {
            int a = domino[0], b = domino[1];
            int key = min(a, b) * 10 + max(a, b); // Unique key for [a, b] and [b, a]
            freq[key]++;
        }

        // Calculate the number of equivalent pairs
        int result = 0;
        for (const auto& [key, count] : freq) {
            if (count > 1) {
                result += (count * (count - 1)) / 2; // Combination formula
            }
        }

        return result;
    }
};
