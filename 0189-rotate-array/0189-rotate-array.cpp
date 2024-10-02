class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::rotate(nums.begin(), nums.size()+nums.begin()-k, nums.end());
    }
};