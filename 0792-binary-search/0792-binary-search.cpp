class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int mid = start + (end-start)/2;
        while(start<=end) {
            if(nums[mid]==target) return mid;
            if(target>nums[mid]) 
            // right me jao
            start = mid+1;
            if(target<nums[mid]) 
            // left me jao
            end=mid-1;

            // ye main bhul jata hu
            mid = start + (end-start)/2;        
            }
            /*
            agar mein yha phuch gya
            iska mtlb element nhi mila
            not found -> return -1;
            */
            
    return -1;
    }
};