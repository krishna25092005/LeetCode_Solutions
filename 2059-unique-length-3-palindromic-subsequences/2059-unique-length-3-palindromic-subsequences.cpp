class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, -1), last(26, -1);
        int n = s.size();
        
        // Find the first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        int result = 0;
        
        // Check for unique palindromes for each character
        for (int i = 0; i < 26; i++) {
            if (first[i] != -1 && last[i] != -1 && first[i] < last[i]) {
                unordered_set<char> middleChars;
                for (int j = first[i] + 1; j < last[i]; j++) {
                    middleChars.insert(s[j]);
                }
                result += middleChars.size();
            }
        }
        
        return result;
    }
};
