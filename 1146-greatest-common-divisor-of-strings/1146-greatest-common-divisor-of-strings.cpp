class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if str1 + str2 is the same as str2 + str1
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // Find the GCD of the lengths of the two strings
        int gcdLength = gcd(str1.size(), str2.size());

        // Return the substring of the first string up to gcdLength
        return str1.substr(0, gcdLength);
    }

private:
    // Helper function to find GCD of two integers
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
