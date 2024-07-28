class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // function complete karna hai
        // vector -> array

        int ans=0;
        int n= nums.size();
        for(int i=0;i<n;i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};