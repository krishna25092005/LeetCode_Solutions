class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int original = x;
        long reversed = 0;

        while (x != 0) {
            int ld = x % 10;
            reversed = (reversed * 10) + ld;
            x /= 10;
        }
        return (original == reversed);
    }
};