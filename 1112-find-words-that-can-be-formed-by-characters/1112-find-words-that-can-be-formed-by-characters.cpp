class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // Frequency map for chars
        vector<int> charCount(26, 0);
        for (char c : chars) {
            charCount[c - 'a']++;
        }
        
        int totalLength = 0;

        // Check each word
        for (const string& word : words) {
            vector<int> wordCount(26, 0);
            for (char c : word) {
                wordCount[c - 'a']++;
            }
            
            // Check if word can be formed
            bool canForm = true;
            for (int i = 0; i < 26; i++) {
                if (wordCount[i] > charCount[i]) {
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                totalLength += word.length();
            }
        }
        
        return totalLength;
    }
};
