class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Frequency map for elements in arr1
        unordered_map<int, int> freq;
        for (int num : arr1) {
            freq[num]++;
        }
        
        // Result vector
        vector<int> result;
        
        // Add elements according to arr2's order
        for (int num : arr2) {
            if (freq.count(num)) {
                result.insert(result.end(), freq[num], num);
                freq.erase(num); // Remove from map after processing
            }
        }
        
        // Add remaining elements (not in arr2), sorted
        vector<int> remaining;
        for (const auto& [num, count] : freq) {
            remaining.insert(remaining.end(), count, num);
        }
        sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());
        
        return result;
    }
};
