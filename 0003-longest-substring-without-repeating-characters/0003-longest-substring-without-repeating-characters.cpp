class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Hash map to store the last index of each character
        unordered_map<char, int> lastSeen;
        int maxLength = 0;  // To store the maximum length of substring
        int start = 0;      // Start index of the current window
        
        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            
            // If the character is already in the substring, move the start pointer
            if (lastSeen.find(currentChar) != lastSeen.end() && lastSeen[currentChar] >= start) {
                start = lastSeen[currentChar] + 1;
            }
            
            // Update the last index of the current character
            lastSeen[currentChar] = end;
            
            // Calculate the length of the current substring
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
