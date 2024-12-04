class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // Create a set to keep track of seen elements
        unordered_set<int> seen;
        
        // Iterate through the array
        for (int num : nums) {
            // If the element is already in the set, it's the repeated one
            if (seen.count(num)) {
                return num;
            }
            // Otherwise, add it to the set
            seen.insert(num);
        }
        
        // This line should never be reached because we are guaranteed one repeated element
        return -1;
    }
};
