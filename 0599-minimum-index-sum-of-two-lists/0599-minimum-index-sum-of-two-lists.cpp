class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        vector<string> result;
        int minIndexSum = INT_MAX;

        // Store indices of strings in list1
        for (int i = 0; i < list1.size(); ++i) {
            indexMap[list1[i]] = i;
        }

        // Check strings in list2
        for (int j = 0; j < list2.size(); ++j) {
            if (indexMap.find(list2[j]) != indexMap.end()) {
                int indexSum = j + indexMap[list2[j]];
                if (indexSum < minIndexSum) {
                    // Found a smaller index sum, update result
                    result = {list2[j]};
                    minIndexSum = indexSum;
                } else if (indexSum == minIndexSum) {
                    // Found another string with the same minimum index sum
                    result.push_back(list2[j]);
                }
            }
        }

        return result;
    }
};