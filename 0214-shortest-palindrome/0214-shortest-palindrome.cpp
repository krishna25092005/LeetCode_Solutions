class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end()); // Reverse the string

        string combined = s + "#" + rev; // Concatenate with a separator
        int n = combined.size();
        
        // Build KMP failure table
        vector<int> lps(n, 0); // Longest prefix-suffix array
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1]; // Previous match length
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1]; // Backtrack
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }

        // Length of the longest prefix which is also a suffix
        int longestPrefix = lps[n - 1];

        // Add the remaining part of the reversed string to the front
        string toAdd = rev.substr(0, rev.size() - longestPrefix);
        return toAdd + s;
    }
};