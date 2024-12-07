class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Create a sorted copy of the array and remove duplicates
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()), sortedArr.end());
        
        // Create a map to store the rank of each unique element
        unordered_map<int, int> rankMap;
        for (int i = 0; i < sortedArr.size(); ++i) {
            rankMap[sortedArr[i]] = i + 1; // Rank starts from 1
        }
        
        // Replace each element in the original array with its rank
        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result[i] = rankMap[arr[i]];
        }
        
        return result;
    }
};
