class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> answer(n, INT_MAX);
        
        // Left to right pass
        int lastSeen = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                lastSeen = i;
            }
            if (lastSeen != -1) {
                answer[i] = i - lastSeen;
            }
        }
        
        // Right to left pass
        lastSeen = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == c) {
                lastSeen = i;
            }
            if (lastSeen != -1) {
                answer[i] = min(answer[i], lastSeen - i);
            }
        }
        
        return answer;
    }
};