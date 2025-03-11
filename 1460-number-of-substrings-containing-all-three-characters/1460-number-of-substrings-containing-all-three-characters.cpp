class Solution {
public:
    int numberOfSubstrings(string s) {
        int count[3] = {0}; // To store frequency of 'a', 'b', 'c'
        int left = 0, result = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right] - 'a']++;  // Update count of the current character

            // Check if we have at least one 'a', 'b', and 'c'
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += s.size() - right; // Add all valid substrings
                count[s[left] - 'a']--; // Shrink window from left
                left++;
            }
        }

        return result;
    }
};
