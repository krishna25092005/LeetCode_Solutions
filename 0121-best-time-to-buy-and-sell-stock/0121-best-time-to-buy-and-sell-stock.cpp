#include <vector>
#include <algorithm> // for std::min and std::max

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = INT_MAX; // Track the lowest price seen so far
        int maxProfit = 0;      // Track the maximum profit
        
        for (int price : prices) {
            // Update the minimum price if the current price is lower
            minPrice = std::min(minPrice, price);
            
            // Calculate the profit if selling at the current price
            int profit = price - minPrice;
            
            // Update the maximum profit if the current profit is greater
            maxProfit = std::max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};
