class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        
        // If n is odd, add 0 in the middle
        if (n % 2 == 1) {
            result.push_back(0);
        }
        
        // Add pairs of numbers that cancel each other out
        for (int i = 1; i <= n / 2; ++i) {
            result.push_back(i);    // Positive number
            result.push_back(-i);   // Negative number
        }
        
        return result;
    }
};
