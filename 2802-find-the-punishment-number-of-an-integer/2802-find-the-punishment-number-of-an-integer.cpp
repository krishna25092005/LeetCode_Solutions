class Solution {
public:
    bool canPartition(string num, int target, int index, int sum) {
        if (index == num.size()) {
            return sum == target;
        }
        
        int currentSum = 0;
        for (int j = index; j < num.size(); ++j) {
            currentSum = currentSum * 10 + (num[j] - '0');
            if (currentSum + sum > target) break;
            if (canPartition(num, target, j + 1, sum + currentSum)) {
                return true;
            }
        }
        
        return false;
    }
    
    int punishmentNumber(int n) {
        int totalSum = 0;
        
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string squareStr = to_string(square);
            if (canPartition(squareStr, i, 0, 0)) {
                totalSum += square;
            }
        }
        
        return totalSum;
    }
};
