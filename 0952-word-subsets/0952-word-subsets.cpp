class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Create a frequency array for the maximum requirements of words2
        vector<int> maxFreq(26, 0);
        
        // Calculate the maximum frequency required for each letter across all words in words2
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        
        // Result vector to store universal strings from words1
        vector<string> result;
        
        // Check each word in words1
        for (const string& word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};