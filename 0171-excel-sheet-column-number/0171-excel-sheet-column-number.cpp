#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (char c : columnTitle) {
            // Convert the character to its numeric value
            int value = c - 'A' + 1;
            // Update the result based on base-26 logic
            result = result * 26 + value;
        }

        return result;
    }
};
