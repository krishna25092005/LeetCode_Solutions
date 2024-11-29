class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        // Define the rows of the keyboard
        unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        
        vector<string> result;
        
        for (const string& word : words) {
            // Determine which row the first letter belongs to
            char firstLetter = tolower(word[0]);
            unordered_set<char>* row = nullptr;
            if (row1.count(firstLetter)) row = &row1;
            else if (row2.count(firstLetter)) row = &row2;
            else if (row3.count(firstLetter)) row = &row3;
            
            // Check if all letters belong to the same row
            bool isValid = true;
            for (char c : word) {
                if (!row->count(tolower(c))) {
                    isValid = false;
                    break;
                }
            }
            
            // Add the word to the result if valid
            if (isValid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
