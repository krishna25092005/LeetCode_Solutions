class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller, equal, greater;

        // Step 1: Partition the elements
        for (int num : nums) {
            if (num < pivot) 
                smaller.push_back(num);
            else if (num == pivot) 
                equal.push_back(num);
            else 
                greater.push_back(num);
        }

        // Step 2: Concatenate the three partitions
        vector<int> result;
        result.insert(result.end(), smaller.begin(), smaller.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());

        return result;
    }
};
