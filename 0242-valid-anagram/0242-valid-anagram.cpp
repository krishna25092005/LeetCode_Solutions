class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Check if lengths are equal
        if (s.length() != t.length()) {
            return false;
        }

        // Step 2: Create a frequency array for counting characters
        vector<int> freq(26, 0); // 26 for lowercase English letters

        // Step 3: Count characters in `s` and `t`
        for (int i = 0; i < s.length(); ++i) {
            freq[s[i] - 'a']++; // Increment for `s`
            freq[t[i] - 'a']--; // Decrement for `t`
        }

        // Step 4: Check if all counts are zero
        for (int count : freq) {
            if (count != 0) {
                return false; // Not an anagram
            }
        }

        return true; // Strings are anagrams
    }
};
