class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;  // Initialize carry
        int i = a.size() - 1;  // Pointer for string a (rightmost bit)
        int j = b.size() - 1;  // Pointer for string b (rightmost bit)

        // Process both strings from right to left
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;  // Start with carry
            
            if (i >= 0) {
                sum += a[i] - '0';  // Convert char to int and add to sum
                i--;  // Move left
            }

            if (j >= 0) {
                sum += b[j] - '0';  // Convert char to int and add to sum
                j--;  // Move left
            }

            carry = sum / 2;  // Update carry (sum / 2)
            result += (sum % 2) + '0';  // Append the remainder as the next bit
        }

        // Reverse the result since we computed it backwards
        reverse(result.begin(), result.end());
        return result;
    }
};
