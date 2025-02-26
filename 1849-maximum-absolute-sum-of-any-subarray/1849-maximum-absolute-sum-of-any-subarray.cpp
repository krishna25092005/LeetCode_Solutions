class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum = 0, min_sum = 0;
        int current_max = 0, current_min = 0;

        for (int num : nums) {
            current_max = max(num, current_max + num);
            max_sum = max(max_sum, current_max);

            current_min = min(num, current_min + num);
            min_sum = min(min_sum, current_min);
        }

        return max(abs(max_sum), abs(min_sum));
    }
};
