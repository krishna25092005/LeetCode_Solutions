class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeroCount = 0;

        // Count the number of zeroes in the array
        for (int num : arr) {
            if (num == 0) {
                zeroCount++;
            }
        }

        // Work from the end of the array
        int i = n - 1;
        int j = n + zeroCount - 1; // Virtual extended array size

        // Traverse the array backward
        while (i < j) {
            if (j < n) {
                arr[j] = arr[i]; // Copy the element if it's within bounds
            }
            if (arr[i] == 0) {
                j--; // Decrement `j` for the duplicated zero
                if (j < n) {
                    arr[j] = 0; // Write the duplicated zero if within bounds
                }
            }
            i--;
            j--;
        }
    }
};
