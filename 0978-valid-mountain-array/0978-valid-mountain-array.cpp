class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        int left = 0, right = n - 1;

        // Move `left` pointer to the peak
        while (left + 1 < n && arr[left] < arr[left + 1]) {
            left++;
        }

        // Move `right` pointer to the peak
        while (right - 1 >= 0 && arr[right] < arr[right - 1]) {
            right--;
        }

        // Check if the peak is valid
        return left == right && left > 0 && right < n - 1;
    }
};
