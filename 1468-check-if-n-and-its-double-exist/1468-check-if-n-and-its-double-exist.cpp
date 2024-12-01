class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen; // To store numbers we've encountered

        for (int num : arr) {
            // Check if the double or half of the current number exists in the set
            if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            // Add the current number to the set
            seen.insert(num);
        }

        return false; // No such pair found
    }
};
