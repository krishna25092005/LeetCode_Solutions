class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev1 = 2, prev2 = 1; // Base cases: f(2) = 2, f(1) = 1
        for (int i = 3; i <= n; ++i) {
            int curr = prev1 + prev2; // f(i) = f(i-1) + f(i-2)
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
