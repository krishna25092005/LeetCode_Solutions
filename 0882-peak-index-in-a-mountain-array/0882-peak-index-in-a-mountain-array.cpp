class Solution {
    // Time Complexity : O(logn)
    // Space Complexity : O(1)
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int n=arr.size();
        int e=n-1;
        int mid=s+(e-s)/2;
        int ansIndex = -1;
        while(s<=e) {
            if(arr[mid]<arr[mid+1])
            s=mid+1;
            else {
                // may or may not be -> store & compute
                ansIndex=mid;
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return mid;
    }
};