class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totalOnes = 0;
        
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        int maxScore = 0;
        int leftZeros = 0;
        int rightOnes = totalOnes;
        
        for (int i = 0; i < n - 1; ++i) { 
            if (s[i] == '0') leftZeros++;
            if (s[i] == '1') rightOnes--;
            
            maxScore = max(maxScore, leftZeros + rightOnes);
        }
        
        return maxScore;
    }
};
