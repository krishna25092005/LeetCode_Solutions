class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        
        // If the length of the string is odd, it can't be valid
        if (n % 2 != 0) return false;
        
        // First pass: left to right
        int open = 0, free_open = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                // Locked character, just count it
                if (s[i] == '(') open++;
                else open--;
            } else {
                // Unlocked character, count as a free character
                free_open++;
            }
            
            // If there are more closing brackets than opening ones, it's invalid
            if (open + free_open < 0) return false;
        }
        
        // Second pass: right to left
        open = 0, free_open = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                // Locked character, just count it
                if (s[i] == ')') open++;
                else open--;
            } else {
                // Unlocked character, count as a free character
                free_open++;
            }
            
            // If there are more opening brackets than closing ones, it's invalid
            if (open + free_open < 0) return false;
        }
        
        return true;
    }
};
