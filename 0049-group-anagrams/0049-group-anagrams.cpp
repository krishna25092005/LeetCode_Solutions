class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& str : strs) {
            string key = str; 
            sort(key.begin(), key.end()); // Sort the string to find the anagram key
            anagramGroups[key].push_back(str);
        }
        
        // Collect the groups into the result vector
        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};
