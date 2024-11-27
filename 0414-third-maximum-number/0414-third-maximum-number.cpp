class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> topThree;

        for (int num : nums) {
            topThree.insert(num);
            if (topThree.size() > 3) {
                topThree.erase(topThree.begin()); // Remove the smallest
            }
        }

        // If there are fewer than 3 distinct numbers, return the largest
        if (topThree.size() < 3) {
            return *topThree.rbegin(); // The largest number
        }

        return *topThree.begin(); // The third largest
    }
};