class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) {
            // Cannot create more palindromes than the total number of characters
            return false;
        }

        unordered_map<char, int> freq; // To store frequency of each character

        // Count character frequencies
        for (char c : s) {
            freq[c]++;
        }

        int oddCount = 0; // Count characters with odd frequencies

        // Check how many characters have odd frequencies
        for (auto& entry : freq) {
            if (entry.second % 2 != 0) {
                oddCount++;
            }
        }

        // If k >= oddCount, we can form palindromes
        return oddCount <= k;
    }
};