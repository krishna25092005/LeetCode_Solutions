class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }
        
        if (diff.size() == 0) return true; // Already equal
        if (diff.size() != 2) return false; // More than one swap needed

        // Check if swapping makes them equal
        return (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
    }
};
