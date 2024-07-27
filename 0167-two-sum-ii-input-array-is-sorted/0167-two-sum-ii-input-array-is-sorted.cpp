class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int size = numbers.size();
        int low = 1;
        int high = size;

        while (low < high) {
            int currSum = numbers[low - 1] + numbers[high - 1];
            if (currSum == target) {
                ans.push_back(low);
                ans.push_back(high);
                return ans;
            } else if (currSum > target) {
                high--;
            } else {
                low++;
            }
        }

        return ans; // return an empty vector if no pair is found
    }
};