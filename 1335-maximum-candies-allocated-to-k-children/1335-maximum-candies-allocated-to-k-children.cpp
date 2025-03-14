class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1, high = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            
            for (int candy : candies) {
                count += candy / mid;
            }

            if (count >= k) {
                result = mid;  
                low = mid + 1;  
            } else {
                high = mid - 1; 
            }
        }

        return result;
    }
};
