class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> substrings;
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    substrings.insert(words[i]);
                }
            }
        }
        
        return vector<string>(substrings.begin(), substrings.end());
    }
};
