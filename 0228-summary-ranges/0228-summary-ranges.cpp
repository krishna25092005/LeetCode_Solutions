class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        
        if (n == 0) return ans;
        
        int s = 0;
        
        for (int i = 1; i <= n; ++i) {
            if (i == n || nums[i] != nums[i - 1] + 1) {
                if (s == i - 1) {
                    ans.push_back(to_string(nums[s]));
                } else { 
                    ans.push_back(to_string(nums[s]) + "->" + to_string(nums[i - 1]));
                }
                s = i;
            }
        }
        
        return ans;
    }
};
