class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // Convert the paragraph to lowercase and replace non-alphanumeric characters with spaces
        for (char& c : paragraph) {
            if (isalpha(c)) {
                c = tolower(c);
            } else {
                c = ' ';
            }
        }
        
        // Create a set of banned words for quick lookup
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        
        // Split the paragraph into words
        unordered_map<string, int> wordCount;
        stringstream ss(paragraph);
        string word;
        while (ss >> word) {
            if (bannedSet.find(word) == bannedSet.end()) {
                wordCount[word]++;
            }
        }
        
        // Find the most frequent word
        string mostCommon;
        int maxCount = 0;
        for (const auto& [key, value] : wordCount) {
            if (value > maxCount) {
                maxCount = value;
                mostCommon = key;
            }
        }
        
        return mostCommon;
    }
};