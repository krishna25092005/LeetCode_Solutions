class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Create a mapping for the custom order
        unordered_map<char, int> charOrder;
        for (int i = 0; i < order.size(); ++i) {
            charOrder[order[i]] = i;
        }
        
        // Compare adjacent words
        for (int i = 0; i < words.size() - 1; ++i) {
            if (!isSorted(words[i], words[i + 1], charOrder)) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    // Helper function to compare two words
    bool isSorted(const string& word1, const string& word2, unordered_map<char, int>& charOrder) {
        int len1 = word1.size(), len2 = word2.size();
        for (int i = 0; i < min(len1, len2); ++i) {
            // Compare characters using the custom order
            if (charOrder[word1[i]] < charOrder[word2[i]]) {
                return true;
            } else if (charOrder[word1[i]] > charOrder[word2[i]]) {
                return false;
            }
        }
        // If one word is a prefix of the other, the shorter word should come first
        return len1 <= len2;
    }
};
