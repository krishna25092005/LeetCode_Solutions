class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int n = s.size();
        int start = 0, maxLength = 0;

        // Helper function to expand around the center
        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // Return the length of the palindrome
            return right - left - 1;
        };

        for (int i = 0; i < n; i++) {
            // Odd-length palindrome
            int len1 = expandAroundCenter(i, i);
            // Even-length palindrome
            int len2 = expandAroundCenter(i, i + 1);
            
            // Take the longer of the two
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
