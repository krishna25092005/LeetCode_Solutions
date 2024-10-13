class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // Solving using STL - One Liner \U0001f60e\U0001f60e
        // Time Complexity : O(n)
        // Space Complexity : O(1)
        next_permutation(nums.begin(), nums.end());
    }
};