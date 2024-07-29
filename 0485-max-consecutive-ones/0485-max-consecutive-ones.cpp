class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int maxCount = 0;      
        int currentCount = 0;

        for (int num : nums) {
            if (num == 1) {
                currentCount++;
            } else {
                maxCount = std::max(maxCount, currentCount);
                currentCount = 0; 
            }
        }
        return std::max(maxCount, currentCount);
    }
};