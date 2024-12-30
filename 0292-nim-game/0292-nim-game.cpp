class Solution {
public:
    bool canWinNim(int n) {
        // If n is not a multiple of 4, you can win
        return n % 4 != 0;
    }
};