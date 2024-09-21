class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int s = 0;
        int n = arr.size();
        int e = n - 1;
        
        while (s < e) {
            int mid = s + (e - s) / 2;
            
            // Check if mid is even, so that we can compare with its pair
            if (mid % 2 == 1) mid--; 
            
            // Check the pair (mid and mid+1)
            if (arr[mid] == arr[mid + 1]) {
                // Single element is in the right half
                s = mid + 2;
            } else {
                // Single element is in the left half
                e = mid;
            }
        }
        return arr[s];
    }
};
