class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case directly
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; 
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        long long quotient = 0;

        for (int i = 31; i >= 0; i--) {
            if ((absDivisor << i) <= absDividend && (absDivisor << i) > 0) {
                absDividend -= (absDivisor << i);
                quotient += (1LL << i);
            }
        }

        quotient = isNegative ? -quotient : quotient;

        if (quotient > INT_MAX) {
            return INT_MAX;
        }
        if (quotient < INT_MIN) {
            return INT_MIN;
        }

        return quotient;
    }
};
