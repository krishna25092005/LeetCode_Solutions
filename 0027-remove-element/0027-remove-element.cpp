class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto ans = remove(nums.begin(), nums.end(), val);
        nums.erase(ans, nums.end());
        return nums.size();
    }
};
